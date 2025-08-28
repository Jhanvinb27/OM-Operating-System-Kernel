#include "scheduler.h"
#include "queue.h"

pcb_t pcb_table[NUM_PCBS];
pcb_t* current_running;

int spawn(const char* name) {
    // Lookup process and initialize PCB
    return 0; // return pid
}

int kill(int pid) {
    // Mark process as terminated, remove from queues
    return 0;
}

int wait(int pid) {
    // Block caller until pid terminates
    return 0;
}
