#include "uls.h"

void mx_sort_arrstr(int flag_r, char ***arr_str) {
    char **ptr = *arr_str;
    char *temp = NULL;

    for (int i = 0; ptr[i] != NULL; i++) {
        for (int j = i + 1; ptr[j] != NULL; j++) {
            if ((flag_r == 0 && mx_strcmp(ptr[i], ptr[j]) > 0)
                || (flag_r == 1 && mx_strcmp(ptr[i], ptr[j]) < 0)) {
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}
