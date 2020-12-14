#ifndef _MYFS_H_
#define _MYFS_H_

#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

#define false 0
#define true 1

#define BIT unsigned
#define BLOCK_SIZE_BYTES 4096
#define NUM_BITS (BLOCK_SIZE_BYTES/sizeof(BIT))
#define MAX_BLOCKS_WITH_NODES 5
#define MAX_BLOCKS_PER_FILE 100
#define MAX_FILES_PER_DIRECTORY 100
#define MAX_LEN_FILE_NAME 15
#define DISK_LBA int
#define BOOLEAN int

#define SUPERBLOCK_IDX 0
#define BITMAP_IDX 1
#define DIRECTORY_IDX 2
#define NODES_IDX 3

// STRUCTS
typedef struct FileStructure {
    int  nodeIdx;                         	// Associated i-node
    char fileName[MAX_LEN_FILE_NAME + 1];	// File name
    BOOLEAN freeFile;                       // Free file
} FileStruct;

typedef struct DirectoryStructure {
    int numFiles;                          		// Num files
    FileStruct files[MAX_FILES_PER_DIRECTORY];	// Files
} DirectoryStruct;

typedef struct NodeStructure {
    int numBlocks;                        		// Num blocks
    int fileSize;                        		// File size
    time_t modificationTime;              		// Modification time
    DISK_LBA blocks[MAX_BLOCKS_PER_FILE];		// Blocks
    BOOLEAN freeNode;                        	// If the node is available
} NodeStruct;

#define NODES_PER_BLOCK (BLOCK_SIZE_BYTES/sizeof(NodeStruct))
#define MAX_NODES (NODES_PER_BLOCK * MAX_BLOCKS_WITH_NODES)

typedef struct SuperBlockStructure {
    time_t creationTime;     	// Creation time
    int diskSizeInBlocks;    	// # blocks in disk
    int numOfFreeBlocks;     	// # of available blocks
    int blockSize;            	// Block size
    int maxLenFileName;  		// Max. length of a file name
    int maxBlocksPerFile; 		// Max. number of blocks per file
} SuperBlockStruct;

typedef struct MyFileSystemStructure {
    int fdVirtualDisk;             		// File descriptor where the whole filesystem is stored
    SuperBlockStruct superBlock;   		// Super block
    BIT bitMap[NUM_BITS];            	// Bit map
    DirectoryStruct directory;     		// Root directory
    NodeStruct* nodes[MAX_NODES];		// Array of inode pointers
    int numFreeNodes;                  // # of available inodes
} MyFileSystem;


/**
 * @brief Copies the content from one node to another
 *
 * @param dest destination node
 * @param src source node
 * @return void
 **/
void copyNode(NodeStruct *dest, NodeStruct *src);

/**
 * @brief Looks for the index a file has in the directory
 *
 * @param myFileSystem pointer to the FS
 * @param fileName name of the file we are looking for
 * @return index of the file in the array of files, -1 if the file is not found
 **/
int findFileByName(MyFileSystem *myFileSystem, char *fileName);

/**
 * @brief This function looks for a free entry in the array of files
 *
 * @param myFileSystem pointer to the FS
 * @return index of a free entry in the array of files, -1 if it does not exist
 **/
int findFreeFile(MyFileSystem *myFileSystem);

/**
 * @brief Looks for an available node
 *
 * @param myFileSystem pointer to the FS
 * @return number of a free inode, -1 if not able to find one
 **/
int findFreeNode(MyFileSystem *myFileSystem);

/**
 * @brief Computes the position (byte) of a given inode in the backup file
 *
 * @param inodeNum given inode (is position in the backup file)
 * @return the offset, or the starting position of the given inode
 **/
int findNodeByPos(int nodeNum);

/**
 * @brief It reads the inodes from disk and store them in new structures myFileSystem->nodes[i]
 *
 * @param myFileSystem pointer to the FS
 * @return 0 on success and <0 on error
 **/
int initializeNodes(MyFileSystem *myFileSystem);

/**
 * @brief Initializes the super block
 *
 * @param myFileSystem pointer to the FS
 * @param diskSize size of the backup file for the FS
 * @return void
 **/
void initializeSuperBlock(MyFileSystem *myFileSystem, int diskSize);

/**
 * @brief Free all the memory linked to the current FS
 *
 * @param myFileSystem pointer to the FS
 * @return void
 **/
void myFree(MyFileSystem *myFileSystem);

/**
 * @brief Formats the current disk. Saves all the bitmap, super block and the directory.
 *
 * @param myFileSystem pointer to the FS
 * @param diskSize size of the disk we are creating
 * @param backupFileName Name of the file that will store the FS
 * @return 0 on success and <0 on error
 **/
int myMkfs(MyFileSystem *myFileSystem, int diskSize, char *backupFileName);

/**
 * @brief Mounts the current disk.  (Optional part of the lab assignment)
 *
 * @param myFileSystem pointer to the FS
 * @param backupFileName Name of the file that stores the FS
 * @return 0 on success and <0 on error
 **/
int myMount(MyFileSystem *myFileSystem, char *backupFileName);


/**
 * @brief Returns the number of free blocks in the FS, checking the bitmap
 *
 * @param myFileSystem pointer to the FS
 * @return number of free blocks
 **/
int myQuota(MyFileSystem *myFileSystem);

/**
 * @brief Reads an inode from the backup file
 *
 * @param myFileSystem pointer to the FS
 * @param nodeNum inode number (position in backup file)
 * @param node inode structure that will contain the information read from the backup file
 * @return 0 on success and -1 on error
 **/
int readNode(MyFileSystem *myFileSystem, int nodeNum, NodeStruct* node);

/**
 * @brief This function looks for empty blocks in the bitmap, reserving them
 *
 * @param myFileSystem pointer to the FS
 * @param blockIdxs array of blocks reserved by an inode (initially empty)
 * @param numBlocks number of blocks we want to reserve
 * @return 0 on success and -1 on error
 **/
int reserveBlocksForNodes(MyFileSystem* myFileSystem, DISK_LBA blockIdxs[], int numBlocks);

/**
 * @brief Writes all the information of the bitmap into the backup file
 *
 * @param myFileSystem pointer to the FS
 * @return 0 on success and <0 on error
 **/
int updateBitmap(MyFileSystem *myFileSystem);

/**
 * @brief Writes the informatin of the directory into the backup file
 *
 * @param myFileSystem pointer to the FS
 * @return int
 **/
int updateDirectory(MyFileSystem *myFileSystem);

/**
 * @brief Writes all the information of an inode into the backup file
 *
 * @param myFileSystem pointer to the FS
 * @param inodeNum inode number
 * @param inode structure of the inode to write (it does not have to match with myFileSystem.inodes[inodeIdx])
 * @return 0 on success and <0 on error
 **/
int updateNode(MyFileSystem *myFileSystem, int nodeNum, NodeStruct *node);

/**
 * @brief Writes all the information of the superblock in the backup file
 *
 * @param myFileSystem pointer to the FS
 * @return 0 on success and <0 on error
 **/
int updateSuperBlock(MyFileSystem *myFileSystem);


/**
 * @brief Reads numBlock from storage into buffer
 *
 * @param myFileSystem pointer to the FS
 * @param blockNumber block to be read
 * @param buffer with space for block data
 * @return 0 on success and -1 on error
 **/
int readBlock(MyFileSystem *myFileSystem, DISK_LBA blockNumber, void *buffer);


/**
 * @brief Writes buffer data into numBlock storage block
 *
 * @param myFileSystem pointer to the FS
 * @param blockNumber storage block number
 * @param buffer data to be written
 * @return 0 on success and -1 on error
 **/
int writeBlock(MyFileSystem *myFileSystem, DISK_LBA blockNumber, void *buffer);


#endif
