#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n) {
    unsigned char *d = (unsigned char *) dst;
    unsigned char *s = (unsigned char *) src;

    while (n--) {
        *d++ = *s++;
        if (*s == c) {
            *d = *s;
            return (d + 1);
        }
    }
    return NULL;
}
