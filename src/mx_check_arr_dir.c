#include "uls.h"

static void sx_delete_illegal_dirname(char ***arr_ptr, char **str_ptr);

void mx_check_arr_dir(char ***arr_dirname) {
    char **arr = *arr_dirname;

    if (*arr_dirname == NULL)
        return;
    while (*arr) {
        if (!mx_legal_dirname(*arr)) {
            mx_print_wrong_dir(*arr);
            sx_delete_illegal_dirname(arr_dirname, arr);
            continue;
        }
        arr++;
    }
}

static void sx_delete_illegal_dirname(char ***arr_ptr, char **str_ptr) {
    char **arr = *arr_ptr;
    char **ptr_del = NULL;
    char *del = NULL;

    while (*arr) {
        if (arr == str_ptr) {
            del = *arr;
            while (*(arr + 1) != NULL) {
                *arr = *(arr + 1);
                arr++;
            }
            ptr_del = arr + 1;
            *arr = NULL;
            mx_strdel(&del);
            break;
        }
        arr++;
    }
}
