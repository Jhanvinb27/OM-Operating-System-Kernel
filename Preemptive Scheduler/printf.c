#include "printf.h"
#include "util.h"

void printf(const char *fmt, ...) {
    // Minimal printf: only handles %d and %s
    va_list args;
    va_start(args, fmt);
    while(*fmt) {
        if(*fmt == '%') {
            fmt++;
            if(*fmt == 'd') print_int(va_arg(args, int));
            if(*fmt == 's') print_str(va_arg(args, char*));
        } else {
            print_str((char[]){*fmt,0});
        }
        fmt++;
    }
    va_end(args);
}
