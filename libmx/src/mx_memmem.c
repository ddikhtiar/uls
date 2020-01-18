#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len,
const void *little, size_t little_len) {
    unsigned const char *b = big;
    unsigned const char *l = little;

    if (little_len > big_len || !big_len || !little_len)
        return NULL;
    else if (little_len == 0)
        return (void *) big;
    else
        return mx_strstr((const char *)b, (const char *)l);
}
