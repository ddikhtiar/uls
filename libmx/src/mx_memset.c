#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *box = b;

    while(len--)
        *box++ = c;
    return box;
}
