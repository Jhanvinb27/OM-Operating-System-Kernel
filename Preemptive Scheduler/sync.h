#ifndef SYNC_H
#define SYNC_H

#include "queue.h"

typedef struct semaphore {
    int value;
    queue_t wait_queue;
} semaphore_t;

void semaphore_init(semaphore_t *sem, int value);
void semaphore_down(semaphore_t *sem);
void semaphore_up(semaphore_t *sem);

#endif
