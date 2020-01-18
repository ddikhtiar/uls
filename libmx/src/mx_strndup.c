#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    unsigned long len;
    char *copy = NULL;

    if (s1 == NULL)
        return NULL;
    if (mx_strlen(s1) > (int) n)
        len = n;
    else
        len = mx_strlen(s1);
    copy = mx_strnew(len);
    if (copy == NULL)
        return NULL;
    else {
        copy = mx_strncpy(copy, s1, len);
        return copy;
    }
}
