#include "util.h"

uint64_t get_timer() {
    extern uint64_t time_elapsed;
    return time_elapsed;
}

void print_str(const char *s) {
    while(*s) {
        asm volatile("int $0x10" : : "a"(0x0E00 | *s++));
    }
}

void print_int(int n) {
    char buf[12];
    itoa(n, buf, 10);
    print_str(buf);
}
