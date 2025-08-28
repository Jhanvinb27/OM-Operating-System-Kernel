#include "common.h"

unsigned int get_timer() {
    static unsigned int counter = 0;
    return counter++;  // dummy increment for timing
}

void print_str(const char *s) {
    while (*s) {
        putchar(*s++);
    }
}

void print_int(unsigned int n) {
    char buf[12];
    snprintf(buf, sizeof(buf), "%u", n);
    print_str(buf);
}
