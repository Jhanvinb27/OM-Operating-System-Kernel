#include "util.h"

void memset(void* s, int c, int n) {
    unsigned char* p = s;
    for(int i=0;i<n;i++) p[i] = c;
}

void memcpy(void* dest, const void* src, int n) {
    unsigned char* d = dest;
    const unsigned char* s = src;
    for(int i=0;i<n;i++) d[i] = s[i];
}
