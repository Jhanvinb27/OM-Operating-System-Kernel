#include "queue.h"
#include <stdlib.h>

void enqueue(queue_t* q, node_t* node) {
    node->next = NULL;
    if (!q->head) q->head = node;
    else q->tail->next = node;
    q->tail = node;
}

node_t* dequeue(queue_t* q) {
    if (!q->head) return NULL;
    node_t* node = q->head;
    q->head = node->next;
    if (!q->head) q->tail = NULL;
    return node;
}

void remove_node(queue_t* q, node_t* node) {
    // Remove arbitrary node
}
