#include "uls.h"

void mx_print_wrong_dir(char ***arr_del) {
    char **ptr = NULL;

    mx_sort_arrstr(0, arr_del);
    ptr = *arr_del;
    while (*ptr) {
        mx_printerr("uls: ");
        mx_printerr(*ptr);
        mx_printerr(": No such file or directory\n");
        ptr++;
    }
    mx_del_strarr(arr_del);
}
