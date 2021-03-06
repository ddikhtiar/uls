#include "uls.h"

static char **sx_current_dir() {
    char **arr = NULL;

    arr = (char **) malloc(sizeof(char *) * 2);
    arr[0] = mx_strdup(".");
    arr[1] = NULL;
    return arr;
}

static int sx_num_of_wrong(char ***arr_str) {
    char **ptr = *arr_str;
    int num = 0;

    while(*ptr) {
        if (!mx_legal_dirname(*ptr))
            num++;
        ptr++;
    }
    return num;
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

static void sx_parse(int num, char ***d_true, char ***d_false) {
    char **illegal = *d_false;
    char **arr = *d_true;

    while (*arr) {
        if (!mx_legal_dirname(*arr)) {
            illegal[num - 1] = mx_strdup(*arr);
            sx_delete_illegal_dirname(d_true, arr);
            num--;
            continue;
        }
        arr++;
    }
}

int mx_check_arr_dir(char ***arr_dirname) {
    char **illegal = NULL;
    int wrong = 0;

    if (*arr_dirname == NULL) {
        *arr_dirname = sx_current_dir();
        return 0;
    }
    if ((wrong = sx_num_of_wrong(arr_dirname)) > 0) {
        illegal = (char **) malloc(sizeof(char *) * (wrong + 1));
        illegal[wrong] = NULL;
        sx_parse(wrong, arr_dirname, &illegal);
        mx_print_wrong_dir(&illegal);
    }
    if (mx_number_of_dir(*arr_dirname) == 0)
        return -1;
    else
        return 1;
}
