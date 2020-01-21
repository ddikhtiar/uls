#include "uls.h"

bool mx_find_flag(char ***arr_str, char f_char) {
    char **arr_ptr = *arr_str;
    char *str_ptr = NULL;

    while (*arr_ptr) {
        str_ptr = *arr_ptr + 1;
        while (*str_ptr) {
            if (*str_ptr == f_char)
                return true;
            str_ptr++;
        }
        arr_ptr++;
    }
    return false;
}
