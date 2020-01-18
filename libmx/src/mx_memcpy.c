#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *d = dst;
    unsigned const char *s = src;

    for (unsigned long i = 0; i < n; i++)
        d[i] = s[i];
    return d;
}
