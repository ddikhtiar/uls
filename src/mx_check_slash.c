#include "uls.h"

bool mx_check_slash(const char *str) {
    char *ptr = (char *)str;

    while (*(ptr + 1) != '\0')
        ptr++;
    return (*ptr == '/' ? false : true); 
}
