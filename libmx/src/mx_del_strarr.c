#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **buf = *arr;

    if (*arr != NULL) {
        for (int i = 0; buf[i] != NULL; i++) {
            mx_strdel(&buf[i]);
        }
        free(*arr);
        *arr = NULL;
    }
}
