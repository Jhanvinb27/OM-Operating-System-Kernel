#include "common.h"
#include "scheduler.h"

int scheduler_count = 0;
pcb_t *current_task;

void scheduler() {
    scheduler_count++;

    // Simple round-robin scheduling
    for (int i = 0; i < NUM_TASKS; i++) {
        if (pcbs[i].state == READY) {
            current_task = &pcbs[i];
            restore_context(current_task);
            return;
        }
    }

    // No task ready
    while (1) { }
}

void do_yield() {
    save_context(current_task);
    current_task->state = READY;
    scheduler();
}

void do_exit() {
    current_task->state = TERMINATED;
    scheduler();
}
