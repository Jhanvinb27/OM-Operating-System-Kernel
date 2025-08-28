#include "queue.h"

void init_queue(queue_t *q) {
    q->head = q->tail = 0;
}

int is_queue_empty(queue_t *q) {
    return q->head == q->tail;
}

void enqueue(queue_t *q, pcb_t *task) {
    q->tasks[q->tail++] = task;
}

pcb_t* dequeue(queue_t *q) {
    return q->tasks[q->head++];
}
