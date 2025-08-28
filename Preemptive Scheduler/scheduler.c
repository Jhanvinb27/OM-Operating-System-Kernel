#include "scheduler.h"
#include "queue.h"
#include "sync.h"
#include "common.h"

pcb_t *current_task;
uint64_t time_elapsed = 0;

void do_yield() {
    save_context(current_task);
    scheduler();
}

void do_exit() {
    current_task->state = TASK_EXITED;
    scheduler();
}

void scheduler() {
    current_task = dequeue_ready();
    restore_context(current_task);
}

void put_current_running() {
    enqueue_ready(current_task);
}
