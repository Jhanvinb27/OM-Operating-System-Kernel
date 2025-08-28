#ifndef SCSI_H
#define SCSI_H

#include "common.h"

int scsi_read(int sector, void *buf, int len);
int scsi_write(int sector, void *buf, int len);
int allocate_swap_space();

#endif
