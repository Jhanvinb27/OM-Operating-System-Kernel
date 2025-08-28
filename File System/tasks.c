#include "common.h"
#include "lock.h"
#include "scheduler.h"

void thread1()
{
    lock_init(&lock1);
    lock_acquire(&lock1);
    do_yield();
    lock_release(&lock1);
    do_exit();
}

void thread2()
{
    while (1)
    {
        do_yield();
    }
}

void thread3()
{
    do_yield();
    lock_acquire(&lock1);
    lock_release(&lock1);
    do_exit();
}

void thread4()
{
    lock_acquire(&lock1);
    lock_release(&lock1);
    do_exit();
}
