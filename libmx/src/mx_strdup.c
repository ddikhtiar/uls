#include "libmx.h"

char *mx_strdup(const char *str) {
    int len;
    char *copy = NULL;

    len = mx_strlen(str);
    copy = mx_strcpy(mx_strnew(len), str);
    if (copy == NULL)
        return NULL;
    else
        return copy;
}
