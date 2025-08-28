#include "scsi.h"
#include "memory.h"

int scsi_read(int sector, void *buf, int len) {
    // Simulate disk read
    memcpy(buf, (void*)(0x100000 + sector * PAGE_SIZE), len);
    return 0;
}

int scsi_write(int sector, void *buf, int len) {
    // Simulate disk write
    memcpy((void*)(0x100000 + sector * PAGE_SIZE), buf, len);
    return 0;
}

int allocate_swap_space() {
    static int next_sector = 0;
    return next_sector++;
}
