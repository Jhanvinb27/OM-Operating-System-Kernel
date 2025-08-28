#ifndef KERNEL_H
#define KERNEL_H

#include "common.h"

typedef struct pcb {
    int pid;
    uint32_t *page_directory;
    int swap_size;
    int swap_loc;
    void *stack_ptr;
} pcb_t;

extern pcb_t pcb_array[NUM_PCBS];
extern pcb_t *current_running;

#endif
