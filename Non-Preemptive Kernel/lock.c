#include "lock.h"
#include "scheduler.h"

void lock_init(lock_t *l) {
    l->held = 0;
    l->queue_head = l->queue_tail = NULL;
}

void lock_acquire(lock_t *l) {
    if (!l->held) {
        l->held = 1;
        return;
    }
    block(current_task, l);
}

void lock_release(lock_t *l) {
    if (l->queue_head != NULL) {
        pcb_t *task = dequeue(l);
        task->state = READY;
    } else {
        l->held = 0;
    }
}
