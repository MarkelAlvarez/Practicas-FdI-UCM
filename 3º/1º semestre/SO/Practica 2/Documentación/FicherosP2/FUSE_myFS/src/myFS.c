#include "myFS.h"
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void copyNode(NodeStruct *dest, NodeStruct *src)
{
    int i;

    dest->numBlocks = src->numBlocks;
    dest->fileSize = src->fileSize;
    dest->modificationTime = src->modificationTime;
    dest->freeNode = src->freeNode;

    for(i = 0; i < MAX_BLOCKS_PER_FILE; i++)
        dest->blocks[i] = src->blocks[i];
}

int findFileByName(MyFileSystem *myFileSystem, char *fileName)
{
    int i;

    for(i = 0; i < MAX_FILES_PER_DIRECTORY; i++) {
        if(myFileSystem->directory.files[i].freeFile == false) {
            if(strcmp(fileName, myFileSystem->directory.files[i].fileName) == 0)
                return i;
        }
    }
    return -1;
}

int findFreeFile(MyFileSystem *myFileSystem)
{
    int i;
    for(i = 0; i < MAX_FILES_PER_DIRECTORY; i++) {
        if(myFileSystem->directory.files[i].freeFile == true)
            return i;
    }
    // There is no a free file
    return -1;
}

int findFreeNode(MyFileSystem* myFileSystem)
{
    int i;
    for(i = 0; i < MAX_NODES; i++) {
        if(myFileSystem->nodes[i] == NULL)
            return i;
    }
    // There is no free inode
    return -1;
}

int findNodeByPos(int nodeNum)
{
    int whichInodeBlock;
    int whichInodeInBlock;
    int inodeLocation;

    whichInodeBlock = nodeNum / NODES_PER_BLOCK;
    whichInodeInBlock = nodeNum % NODES_PER_BLOCK;

    inodeLocation = (NODES_IDX + whichInodeBlock) * BLOCK_SIZE_BYTES + whichInodeInBlock * sizeof(NodeStruct);
    return inodeLocation;
}

int initializeNodes(MyFileSystem *myFileSystem)
{
    int numNode;
    NodeStruct temp;

    // We read the inodes one by one
    for(numNode = 0; numNode < MAX_NODES; numNode++) {
        if(readNode(myFileSystem, numNode, &temp))
            return -1;
        // Free inode?
        if(temp.freeNode) {
            myFileSystem->nodes[numNode] = NULL;
        }
        // We alloc. an inode in mem. and copy the content from the backup file
        else {
            if( (myFileSystem->nodes[numNode] = malloc(sizeof(NodeStruct)))==NULL) {
                perror("Error in malloc");
                return -2;
            }
            copyNode(myFileSystem->nodes[numNode], &temp);
            myFileSystem->numFreeNodes--;
        }
    }
    return 0;
}

void initializeSuperBlock(MyFileSystem *myFileSystem, int diskSize)
{
    myFileSystem->superBlock.diskSizeInBlocks = diskSize / BLOCK_SIZE_BYTES;
    myFileSystem->superBlock.numOfFreeBlocks = myQuota(myFileSystem);

    myFileSystem->superBlock.creationTime = time(NULL);

    myFileSystem->superBlock.blockSize = BLOCK_SIZE_BYTES;
    myFileSystem->superBlock.maxLenFileName = MAX_LEN_FILE_NAME;
    myFileSystem->superBlock.maxBlocksPerFile = MAX_BLOCKS_PER_FILE;
}

void myFree(MyFileSystem *myFileSystem)
{
    int i;
    close(myFileSystem->fdVirtualDisk);
    for(i = 0; i < MAX_NODES; i++) {
        free(myFileSystem->nodes[i]);
        myFileSystem->nodes[i] = NULL;
    }
}

int myMkfs(MyFileSystem *myFileSystem, int diskSize, char *backupFileName)
{
    // We create the virtual disk:
    myFileSystem->fdVirtualDisk = open(backupFileName, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

    // Some minimal checks:
    assert(sizeof(SuperBlockStruct) <= BLOCK_SIZE_BYTES);
    assert(sizeof(DirectoryStruct) <= BLOCK_SIZE_BYTES);
    int numBlocks = diskSize / BLOCK_SIZE_BYTES;
    int minNumBlocks = 3 + MAX_BLOCKS_WITH_NODES + 1;
    int maxNumBlocks = NUM_BITS;
    if(numBlocks < minNumBlocks) {
        return -1;
    }
    if(numBlocks >= maxNumBlocks) {
        return -2;
    }

    /// BITMAP
    // Initialization
    int i;
    for(i = 0; i < NUM_BITS; i++) {
        myFileSystem->bitMap[i] = 0;
    }

    // First three blocks will be superblock, bitmap and directory
    myFileSystem->bitMap[BITMAP_IDX] = 1;
    myFileSystem->bitMap[SUPERBLOCK_IDX] = 1;
    myFileSystem->bitMap[DIRECTORY_IDX] = 1;
    // Next MAX_BLOCKS_WITH_NODES will contain inodes
    for(i = 3; i < 3 + MAX_BLOCKS_WITH_NODES; i++) {
        myFileSystem->bitMap[i] = 1;
    }
    updateBitmap(myFileSystem);

    /// DIRECTORY
    // Initialization
    myFileSystem->directory.numFiles = 0;
    for(i = 0; i < MAX_FILES_PER_DIRECTORY; i++) {
        myFileSystem->directory.files[i].freeFile = 1;
    }
    updateDirectory(myFileSystem);

    /// INODES
    NodeStruct currentNode;
    currentNode.freeNode = 1;
    for(i = 0; i < MAX_NODES; i++) {
        updateNode(myFileSystem, i, &currentNode);
    }

    /// SUPERBLOCK
    initializeSuperBlock(myFileSystem, diskSize);
    updateSuperBlock(myFileSystem);
    sync();

    // At the end we have at least one block
    assert(myQuota(myFileSystem) >= 1);

    if(initializeNodes(myFileSystem)) {
        myFree(myFileSystem);
        return -3;
    }

    printf("SF: %s, %d B (%d B/block), %d blocks\n", backupFileName, diskSize, BLOCK_SIZE_BYTES, numBlocks);
    printf("1 block for SUPERBLOCK (%u B)\n", (unsigned int)sizeof(SuperBlockStruct));
    printf("1 block for BITMAP, covering %u blocks, %u B\n", (unsigned int)NUM_BITS, (unsigned int)(NUM_BITS * BLOCK_SIZE_BYTES));
    printf("1 block for DIRECTORY (%u B)\n", (unsigned int)sizeof(DirectoryStruct));
    printf("%d blocks for inodes (%u B/inode, %u inodes)\n", MAX_BLOCKS_WITH_NODES, (unsigned int)sizeof(NodeStruct), (unsigned int)MAX_NODES);
    printf("%d blocks for data (%d B)\n", myFileSystem->superBlock.numOfFreeBlocks, BLOCK_SIZE_BYTES * myFileSystem->superBlock.numOfFreeBlocks);
    printf("Formatting completed!\n");

    return 0;
}

int myQuota(MyFileSystem *myFileSystem)
{
    int freeCount = 0;
    int i;
    // We compute the number of free blocks
    for(i = 0; i < myFileSystem->superBlock.diskSizeInBlocks; i++) {
        // We are currently using a single uint to store each bit in the bitmap.
        // We could use all the bits in a single uint to compact the information
        if(myFileSystem->bitMap[i] == 0) {
            freeCount++;
        }
    }
    return freeCount;
}

int readNode(MyFileSystem *myFileSystem, int nodeNum, NodeStruct* node)
{
    int posNode;
    assert(nodeNum < MAX_NODES);
    posNode = findNodeByPos(nodeNum);

    if( lseek(myFileSystem->fdVirtualDisk, posNode, SEEK_SET)==-1 ||
        read(myFileSystem->fdVirtualDisk, node, sizeof(NodeStruct)) != sizeof(NodeStruct) ) {
        perror("Error when reading an inode");
        return -1;
    }
    return 0;
}

int reserveBlocksForNodes(MyFileSystem *myFileSystem, DISK_LBA blocks[], int numBlocks)
{
    int i = 0;
    int currentBlock = 0;

    while((currentBlock < numBlocks) && (i < NUM_BITS)) {
        if(myFileSystem->bitMap[i] == 0) {
            myFileSystem->bitMap[i] = 1;
            blocks[currentBlock] = i;
            currentBlock++;
        }
        ++i;
    }

    return (i==NUM_BITS)?-1:0;
}

int updateBitmap(MyFileSystem *myFileSystem)
{
    if(lseek(myFileSystem->fdVirtualDisk, BLOCK_SIZE_BYTES * BITMAP_IDX, SEEK_SET) == (off_t) - 1) {
        perror("Failed lseek in updateBitmap");
        return -1;
    }
    if(write(myFileSystem->fdVirtualDisk,
             myFileSystem->bitMap, sizeof(BIT) * NUM_BITS) == -1) {
        perror("Failed write in updateBitmap");
        return -1;
    }
    sync();
    return 0;
}

int updateDirectory(MyFileSystem *myFileSystem)
{
    if(lseek(myFileSystem->fdVirtualDisk, BLOCK_SIZE_BYTES * DIRECTORY_IDX, SEEK_SET) == (off_t) - 1) {
        perror("Failed lseek in updateDirectory");
        return -1;
    }
    if(write(myFileSystem->fdVirtualDisk, &(myFileSystem->directory), sizeof(DirectoryStruct)) == -1) {
        perror("Failed write in updateDirectory");
        return -1;
    }
    sync();
    return 0;
}

int updateNode(MyFileSystem *myFileSystem, int numNode, NodeStruct *node)
{
    int posNodoI;
    assert(numNode < MAX_NODES);
    posNodoI = findNodeByPos(numNode);

    if(lseek(myFileSystem->fdVirtualDisk, posNodoI, SEEK_SET) == (off_t) - 1) {
        perror("Failed lseek in updateNode");
        return -1;
    }
    if(write(myFileSystem->fdVirtualDisk, node, sizeof(NodeStruct)) == -1) {
        perror("Failed write in updateNode");
    }
    sync();
    return 0;
}


int updateSuperBlock(MyFileSystem *myFileSystem)
{
    if(lseek(myFileSystem->fdVirtualDisk, BLOCK_SIZE_BYTES * SUPERBLOCK_IDX, SEEK_SET) == (off_t) - 1) {
        perror("Failed lseek in updateSuperBlock");
        return -1;
    }
    if(write(myFileSystem->fdVirtualDisk, &(myFileSystem->superBlock), sizeof(SuperBlockStruct)) == -1) {
        perror("Failed write in updateSuperBlock");
        return -1;
    }
    sync();
    return 0;
}

/* Code for the optional part of the lab assignment */

int readBitmap(MyFileSystem *myFileSystem)
{
    return -1;
}



int readDirectory(MyFileSystem* myFileSystem)
{
    return -1;
}


int readSuperblock(MyFileSystem* myFileSystem)
{
    return -1;
}

int readInodes(MyFileSystem* myFileSystem)
{
    return -1;
}

int myMount(MyFileSystem *myFileSystem, char *backupFileName)
{
    if ((myFileSystem->fdVirtualDisk = open(backupFileName, O_RDWR))==-1) {
        perror(backupFileName);
        return 1;
    }

    if (readBitmap(myFileSystem)!=0) {
        fprintf(stderr,"Can't read bitmap\n");
        return 2;
    }

    if (readSuperblock(myFileSystem)!=0) {
        fprintf(stderr,"Can't read superblock\n");
        return 3;
    }

    if (readInodes(myFileSystem)!=0) {
        fprintf(stderr,"Can't read inodes\n");
        return 4;
    }

    if (readDirectory(myFileSystem)!=0) {
        fprintf(stderr,"Can't read directory\n");
        return 5;
    }

    printf("SF: %s, %d B (%d B/block), %d blocks\n", backupFileName, myFileSystem->superBlock.diskSizeInBlocks*BLOCK_SIZE_BYTES, BLOCK_SIZE_BYTES, myFileSystem->superBlock.diskSizeInBlocks);
    printf("1 block for SUPERBLOCK (%u B)\n", (unsigned int)sizeof(SuperBlockStruct));
    printf("1 block for BITMAP, covering %u blocks, %u B\n", (unsigned int)NUM_BITS, (unsigned int)(NUM_BITS * BLOCK_SIZE_BYTES));
    printf("1 block for DIRECTORY (%u B)\n", (unsigned int)sizeof(DirectoryStruct));
    printf("%d blocks for inodes (%u B/inode, %u inodes)\n", MAX_BLOCKS_WITH_NODES, (unsigned int)sizeof(NodeStruct), (unsigned int)MAX_NODES);
    printf("%d blocks for data (%d B)\n", myFileSystem->superBlock.numOfFreeBlocks, BLOCK_SIZE_BYTES * myFileSystem->superBlock.numOfFreeBlocks);
    printf("Volume mounted successfully!\n");
    return 0;
}

int readBlock(MyFileSystem *myFileSystem, DISK_LBA blockNumber, void *buffer)
{

    if(blockNumber < 0 || blockNumber >= myFileSystem->superBlock.diskSizeInBlocks) {
        fprintf(stderr,"Firts bocks to be read must be between 0 and %d\n", myFileSystem->superBlock.diskSizeInBlocks-1);
        return -1;
    }

    if( lseek(myFileSystem->fdVirtualDisk, blockNumber*BLOCK_SIZE_BYTES, SEEK_SET) == (off_t)-1 ) {
        perror("Failed lseek in readBlock()");
        return -1;
    }
    if( read(myFileSystem->fdVirtualDisk, buffer, BLOCK_SIZE_BYTES) != BLOCK_SIZE_BYTES ) {
        perror("Failed read in readBlock()");
    }
    return 0;
}

int writeBlock(MyFileSystem *myFileSystem, DISK_LBA blockNumber, void *buffer)
{

    if(blockNumber < 0 || blockNumber >= myFileSystem->superBlock.diskSizeInBlocks) {
        fprintf(stderr,"Firts bocks to be read must be between 0 and %d\n", myFileSystem->superBlock.diskSizeInBlocks-1);
        return -1;
    }

    if( lseek(myFileSystem->fdVirtualDisk, blockNumber*BLOCK_SIZE_BYTES, SEEK_SET) == (off_t)-1 ) {
        perror("Lseek failed in writeBlock()");
        return -1;
    }
    if( write(myFileSystem->fdVirtualDisk, buffer, BLOCK_SIZE_BYTES) != BLOCK_SIZE_BYTES ) {
        perror("Write failed in writeBlock()");
    }
    return 0;
}