#include "uls.h"

void mx_check_unprintable(char **name) {
    char *ptr = *name;

    for (int i = 0; ptr[i] != '\0'; i++) {
        if (ptr[i] < 32 || ptr[i] == 127)
            ptr[i] = '?';
    }
}
