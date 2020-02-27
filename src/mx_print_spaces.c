#include "uls.h"

void mx_print_spaces(const char *str, int max, int flg_G) {
    int len = mx_strlen(str);
    int spaces = max - len;

    if (flg_G == 1) {
        spaces = max - len;
        for (; spaces > 0; spaces--)
            mx_printchar(' ');
    }
    else {
        spaces = (max / 8) - (len / 8);
        for (;spaces > 0; spaces--)
            mx_printchar('\t');
    }
}
