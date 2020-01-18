#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *d = (char *) dst;
    char *s = (char *) src;
    char *box = mx_strnew(len);
    unsigned long i = len;
    unsigned long z = 0;

    while (z < i) {
        box[z] = s[z];
        z++;
    }
    z = 0;
    while (z < i) {
        d[z] = box[z];
        z++;
    }
    free(box);
    return dst;
}
