#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "common.h"
#include "queue.h"

typedef enum { TASK_READY, TASK_RUNNING, TASK_BLOCKED, TASK_EXITED } task_state_t;

typedef struct pcb {
    uint32_t esp, ebp;
    uint32_t nested_count;
    task_state_t state;
    uint64_t wake_time;
} pcb_t;

extern pcb_t *current_task;
extern uint64_t time_elapsed;

void do_yield();
void do_exit();
void scheduler();
void put_current_running();

#endif
