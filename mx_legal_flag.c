#include "uls.h"

static bool sx_isflag(char c) {
    if (c == 'a' || c == 'A' || c == 'l' || c == '1' || c == 'G' || c == 'C'
        || c == 'r' || c == 't' || c == 'u' || c == 'c' || c == 'S'
        || c == 'T' || c == 'R' || c == 'f')
        return true;
    else
        return false;
}

bool mx_legal_flag(char ***arr_str) {
    char **arr_ptr = *arr_str;
    char *str_ptr = NULL;

    while (*arr_ptr) {
        str_ptr = *arr_ptr + 1;
        while (*str_ptr) {
            if (!sx_isflag(*str_ptr))
                return false;
            str_ptr++;
        }
        arr_ptr++;
    }
    return true;
}
