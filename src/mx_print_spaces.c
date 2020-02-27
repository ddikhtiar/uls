#include "uls.h"

void mx_print_spaces(const char *str, int max) {
    int len = mx_strlen(str);
    int spaces = max - len;

    for (; spaces > 0; spaces--)
        mx_printchar(' ');
}
