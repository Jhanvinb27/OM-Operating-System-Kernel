#ifndef FS_H
#define FS_H

#include "common.h"

#define FS_SIZE 1024        // Number of blocks on disk
#define MAX_FILE_NAME 32
#define MAX_OPEN_FILES 16
#define DIRECTORY 1
#define FILE_TYPE 2
#define FREE_INODE -1

typedef struct {
    int inodeNo;        // i-node number
    short type;         // DIRECTORY, FILE_TYPE
    char links;         // number of links
    int size;           // file size in bytes
    int numBlocks;      // number of blocks used
} fileStat;

typedef struct {
    char name[MAX_FILE_NAME];
    int inodeNo;
} dirEntry;

// File descriptor table
typedef struct {
    int inUse;
    int inodeNo;
    int offset;
    int flags;
} fileDescEntry;

extern fileDescEntry fdTable[MAX_OPEN_FILES];

// Function prototypes
void fs_init(void);
int fs_mkfs(void);
int fs_open(char *filename, int flags);
int fs_close(int fd);
int fs_read(int fd, char *buf, int count);
int fs_write(int fd, char *buf, int count);
int fs_lseek(int fd, int offset);
int fs_mkdir(char *dirname);
int fs_rmdir(char *dirname);
int fs_cd(char *dirname);
int fs_link(char *oldpath, char *newpath);
int fs_unlink(char *filename);
int fs_stat(char *filename, fileStat *buf);

#endif
