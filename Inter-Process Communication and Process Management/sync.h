#ifndef SYNC_H
#define SYNC_H

typedef struct lock { int locked; } lock_t;
typedef struct semaphore { int value; } semaphore_t;
typedef struct cond { int count; } cond_t;
typedef struct barrier { int count; int threshold; } barrier_t;

void lock_acquire(lock_t* lock);
void lock_release(lock_t* lock);
void semaphore_down(semaphore_t* sem);
void semaphore_up(semaphore_t* sem);
void condition_wait(cond_t* cond, lock_t* lock);
void condition_signal(cond_t* cond);
void barrier_wait(barrier_t* bar);

#endif
