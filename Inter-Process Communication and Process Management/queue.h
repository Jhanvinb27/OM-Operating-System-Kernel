#ifndef QUEUE_H
#define QUEUE_H

typedef struct node {
    void* data;
    struct node* next;
} node_t;

typedef struct queue {
    node_t* head;
    node_t* tail;
} queue_t;

void enqueue(queue_t* q, node_t* node);
node_t* dequeue(queue_t* q);
void remove_node(queue_t* q, node_t* node);

#endif
