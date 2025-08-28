#include "kernel.h"
#include "scheduler.h"

void kernel_start() {
    init_tasks();
    scheduler();
}
