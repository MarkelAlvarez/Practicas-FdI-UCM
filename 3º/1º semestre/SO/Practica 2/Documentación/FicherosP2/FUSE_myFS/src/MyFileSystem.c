#include "fuseLib.h"
#include "myFS.h"

#include <stdlib.h>
#include <string.h>


MyFileSystem myFileSystem;

#define USAGE			"Usage: %s -t diskSize -a backupFileName -f 'fuse options'\n"
#define EXAMPLE		"Example:\n%s -t 2097152 -a virtual-disk -f '-d -s mount-point'\n"
#define EXAMPLE2 	"Example:\n%s -m -a <virtual-disk> -f '-d -s mount-point'\n"

int main(int argc, char **argv)
{
    myFileSystem.numFreeNodes = MAX_NODES;

    int ret; // Resulting code of the functions call

    int opt, diskSize = -1;
    char *backupFileName = NULL;
    char *argsFUSE = NULL;

    char *argvNew[MAX_FUSE_NARGS];
    char *pTmp;
    int mount=0;

    while((opt = getopt(argc, argv, "t:a:f:m")) != -1) {
        switch(opt) {
        case 't':
            diskSize = atoi(optarg);
            break;
        case 'a':
            backupFileName = optarg;
            break;
        case 'f':
            argsFUSE = optarg;
            break;
        case 'm':
            mount=1;
            break;
        default: /* '?' */
            fprintf(stderr, USAGE, argv[0]);
            fprintf(stderr, EXAMPLE, argv[0]);
            exit(-1);
        }
    }

    if (!mount) {
        // Any parameter missing?
        if(diskSize == -1 || backupFileName == NULL || argsFUSE == NULL) {
            fprintf(stderr, USAGE, argv[0]);
            fprintf(stderr, EXAMPLE, argv[0]);
            exit(-1);
        }

        // Format file without format?
        ret = myMkfs(&myFileSystem, diskSize, backupFileName);
    } else {
        // Any parameter missing?
        if(backupFileName == NULL || argsFUSE == NULL) {
            fprintf(stderr, USAGE, argv[0]);
            fprintf(stderr, EXAMPLE2, argv[0]);
            exit(-1);
        }
        //Mount the file system
        ret = myMount(&myFileSystem, backupFileName);
    }

    if(ret) {
        fprintf(stderr, "Unable to format or mount, error code: %d\n", ret);
        exit(-1);
    }
    fprintf(stderr, "File system available\n");

    // Parse the arguments for FUSE
    argc = 1;
    argvNew[0] = argv[0];

    pTmp = strtok(argsFUSE, " ");
    while(pTmp && argc < MAX_FUSE_NARGS) {
        argvNew[argc++] = pTmp;
        pTmp = strtok(0, " ");
    }

    // We mount the FS, exit with Control-C
    if((ret = fuse_main(argc, argvNew, &myFS_operations, NULL))) {
        fprintf(stderr, "Error when mounting the FUSE file system\n");
        return(ret);
    }

    myFree(&myFileSystem);

    return(0);
}
