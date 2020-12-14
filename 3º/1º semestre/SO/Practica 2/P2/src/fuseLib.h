#ifndef _FUSELIB_H_

#define _FUSELIB_H_

#define FUSE_USE_VERSION 26
#include <fuse.h>
#include "myFS.h"

#define MAX_FUSE_NARGS 64

extern struct fuse_operations myFS_operations;

extern MyFileSystem myFileSystem;

#endif
