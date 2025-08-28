#include "common.h"
#include "scheduler.h"
#include "tasks.h"

#define NUM_TASKS 4

pcb_t pcbs[NUM_TASKS];

void _start() {
    // Initialize PCBs
    for (int i = 0; i < NUM_TASKS; i++) {
        pcbs[i].id = i;
        pcbs[i].state = READY;
    }

    // Start the first task
    scheduler();
}
