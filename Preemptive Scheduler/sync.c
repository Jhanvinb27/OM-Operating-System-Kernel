#include "sync.h"
#include "scheduler.h"
#include "queue.h"

void semaphore_init(semaphore_t *sem, int value) {
    sem->value = value;
    init_queue(&sem->wait_queue);
}

void semaphore_down(semaphore_t *sem) {
    enter_critical();
    if (sem->value > 0) {
        sem->value--;
    } else {
        block_current(&sem->wait_queue);
    }
    leave_critical();
}

void semaphore_up(semaphore_t *sem) {
    enter_critical();
    if (!is_queue_empty(&sem->wait_queue)) {
        unblock_task(dequeue(&sem->wait_queue));
    } else {
        sem->value++;
    }
    leave_critical();
}
