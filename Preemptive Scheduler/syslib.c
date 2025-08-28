#include "syslib.h"
#include "scheduler.h"

void yield() {
    asm volatile("call kernel_entry" : : "a"(0));
}

void exit() {
    asm volatile("call kernel_entry" : : "a"(1));
}
