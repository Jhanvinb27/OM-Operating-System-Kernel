#include "sync.h"

void lock_acquire(lock_t* lock) {
    // Acquire lock
}

void lock_release(lock_t* lock) {
    // Release lock
}

void semaphore_down(semaphore_t* sem) {
    // Decrement semaphore
}

void semaphore_up(semaphore_t* sem) {
    // Increment semaphore
}

void condition_wait(cond_t* cond, lock_t* lock) {
    // Wait on condition
}

void condition_signal(cond_t* cond) {
    // Signal one waiting thread
}

void barrier_wait(barrier_t* bar) {
    // Barrier wait
}
