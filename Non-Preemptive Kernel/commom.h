#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

#define READY 0
#define RUNNING 1
#define TERMINATED 2
#define STACK_SIZE 1024
#define STACK_MIN 0x80000
#define STACK_MAX 0x90000

typedef struct pcb {
    int id;
    int state;
    uint32_t esp;
} pcb_t;

typedef struct lock {
    int held;
    pcb_t *queue_head;
    pcb_t *queue_tail;
} lock_t;

extern pcb_t pcbs[];
extern pcb_t *current_task;
extern lock_t lock1;

#endif
