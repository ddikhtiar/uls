#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned const char *p = s;

    while (n--) {
        if (*p == c)
            return (unsigned char *) p;
        p++;
    }
    return NULL;
}
