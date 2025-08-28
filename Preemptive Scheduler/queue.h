#ifndef QUEUE_H
#define QUEUE_H

#include "scheduler.h"

#define MAX_TASKS 64

typedef struct queue {
    pcb_t *tasks[MAX_TASKS];
    int head, tail;
} queue_t;

void init_queue(queue_t *q);
int is_queue_empty(queue_t *q);
void enqueue(queue_t *q, pcb_t *task);
pcb_t* dequeue(queue_t *q);

#endif
