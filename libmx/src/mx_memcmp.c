#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned const char *ds1 = s1;
    unsigned const char *ds2 = s2;

    for (unsigned long i = 0; i < n; i++) {
        if (ds1[i] != ds2[i])
            return ds1[i] - ds2[i];
    }
    return 0;
}
