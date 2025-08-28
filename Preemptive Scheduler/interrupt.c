#include "interrupt.h"
#include "scheduler.h"

void enable_interrupts() {
    asm volatile("sti");
}

void disable_interrupts() {
    asm volatile("cli");
}

void irq0_handler() {
    time_elapsed++;
    check_sleeping();
    put_current_running();
    scheduler();
}
