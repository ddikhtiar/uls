#include "libmx.h"

char *mx_strdup(const char *str) {
    int len = 0;
    char *copy = NULL;

    if (str != NULL) {
        len = mx_strlen(str);
        copy = mx_strcpy(mx_strnew(len), str);
        if (copy == NULL)
            return NULL;
    }
    return copy;
}
