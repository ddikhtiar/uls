#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int one = 0;
    int words = 0;

    if (!str)
        return -1;
    while (*str) {
        if (*str == c)
            one = 0;
        else if (!one) {
            one = 1;
            words++;
        }
        str++;
    }
    return words;
}
