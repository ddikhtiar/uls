#include "libmx.h"

void mx_str_reverse(char *s) {
    int len;

    if (s != NULL) {
        len = mx_strlen(s);
        for (int i = 0; i < (len / 2); i++) {
            mx_swap_char(&s[i], &s[len - i - 1]);
        }
    }
}
