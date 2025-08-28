#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "queue.h"

#define NUM_PCBS 64

typedef enum { READY, RUNNING, BLOCKED, TERMINATED } state_t;

typedef struct pcb {
    int pid;
    state_t state;
    struct pcb* next;
} pcb_t;

extern pcb_t pcb_table[NUM_PCBS];
extern pcb_t* current_running;

int spawn(const char* name);
int kill(int pid);
int wait(int pid);

#endif
