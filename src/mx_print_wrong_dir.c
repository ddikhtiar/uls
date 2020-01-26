#include "uls.h"

static void sx_sort(char **arr_str);

void mx_print_wrong_dir(char ***arr_del) {
	char **ptr = *arr_del;

    sx_sort(ptr);
	while (*ptr) {
	    mx_printerr("uls: ");
	    mx_printerr(*ptr);
	    mx_printerr(": No such file or directory\n");
	}
	mx_del_strarr(arr_del);
}

static void sx_sort(char **arr_str) {
    char *temp = NULL;

	for (int i = 0; arr_str[i] != NULL; i++) {
		for (int j = i + 1; arr_str[j] != NULL; j++) {
			if (mx_strcmp(arr_str[i], arr_str[j]) > 0) {
				temp = arr_str[i];
				arr_str[i] = arr_str[j];
				arr_str[j] = temp;
			}
		}
	}
}
