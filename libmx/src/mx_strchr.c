#include "libmx.h"

char *mx_strchr(const char *s, int c) {
    for(; ; ++s) {
        if (*s == c)
            return (char*)s;
        if (*s == '\0')
            return NULL;
    }
}
