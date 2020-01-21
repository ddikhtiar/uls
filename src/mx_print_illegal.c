#include "uls.h"

static char sx_illegal_char(char ***arr_str);

void mx_print_illegal(char ***arr_str) {
    char *illeg_flag = mx_strnew(1);

    illeg_flag[0] = sx_illegal_char(arr_str);
    mx_printerr("uls: illegal option -- ");
    mx_printerr(illeg_flag);
    mx_printerr("\n");
    mx_printerr("usage: uls [-l] [file ...]\n");
    mx_strdel(&illeg_flag);
}

static char sx_illegal_char(char ***arr_str) {
    char **arr_ptr = *arr_str;
    char *str_ptr = NULL;
	char c;

    while (*arr_ptr) {
        str_ptr = *arr_ptr + 1;
        while (*str_ptr) {
			c = *str_ptr;
            if (c == 'a' || c == 'A' || c == 'l' || c == '1' || c == 'G'
                || c == 'C' || c == 'r' || c == 't' || c == 'u' || c == 'c'
                || c == 'S' || c == 'T' || c == 'R')
                str_ptr++;
            else
                return c;
        }
        arr_ptr++;
    }
    return '\n';
}
