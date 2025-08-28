#include "fs.h"
#include "block.h"
#include <string.h>
#include <stdio.h>

fileDescEntry fdTable[MAX_OPEN_FILES];

// Initialize filesystem
void fs_init(void) {
    block_init();
    // Check for existing filesystem magic number
    // If not present, call fs_mkfs()
}

// Format disk
int fs_mkfs(void) {
    // Initialize superblock, free block list, root directory
    // Write magic number
    return 0; // success
}

// Open file
int fs_open(char *filename, int flags) {
    for (int i = 0; i < MAX_OPEN_FILES; i++) {
        if (!fdTable[i].inUse) {
            fdTable[i].inUse = 1;
            fdTable[i].inodeNo = 0; // Lookup inode number
            fdTable[i].offset = 0;
            fdTable[i].flags = flags;
            return i;
        }
    }
    return -1;
}

// Close file
int fs_close(int fd) {
    if (fd < 0 || fd >= MAX_OPEN_FILES || !fdTable[fd].inUse)
        return -1;
    fdTable[fd].inUse = 0;
    return 0;
}

// Read file
int fs_read(int fd, char *buf, int count) {
    if (fd < 0 || fd >= MAX_OPEN_FILES || !fdTable[fd].inUse) return -1;
    // Read from file blocks
    return count; // number of bytes read
}

// Write file
int fs_write(int fd, char *buf, int count) {
    if (fd < 0 || fd >= MAX_OPEN_FILES || !fdTable[fd].inUse) return -1;
    // Write to file blocks
    return count; // number of bytes written
}

// Reposition offset
int fs_lseek(int fd, int offset) {
    if (fd < 0 || fd >= MAX_OPEN_FILES || !fdTable[fd].inUse) return -1;
    fdTable[fd].offset = offset;
    return offset;
}

// Create directory
int fs_mkdir(char *dirname) {
    // Create new directory entry
    return 0;
}

// Remove directory
int fs_rmdir(char *dirname) {
    // Check empty, remove blocks
    return 0;
}

// Change directory
int fs_cd(char *dirname) {
    // Update current working directory
    return 0;
}

// Create hard link
int fs_link(char *oldpath, char *newpath) {
    return 0;
}

// Remove file/link
int fs_unlink(char *filename) {
    return 0;
}

// File stats
int fs_stat(char *filename, fileStat *buf) {
    buf->inodeNo = 0;
    buf->type = FILE_TYPE;
    buf->links = 1;
    buf->size = 0;
    buf->numBlocks = 0;
    return 0;
}
