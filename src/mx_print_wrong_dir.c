#include "uls.h"

static void sx_sort(char ***arr_str);

void mx_print_wrong_dir(char ***arr_del) {
	char **ptr = NULL;
	
    sx_sort(arr_del);
	ptr = *arr_del;
	while (*ptr) {
	    mx_printerr("uls: ");
	    mx_printerr(*ptr);
	    mx_printerr(": No such file or directory\n");
		ptr++;
	}
	mx_del_strarr(arr_del);
}

static void sx_sort(char ***arr_str) {
    char **ptr = *arr_str;
	char *temp = NULL;

	for (int i = 0; ptr[i + 1] != NULL; i++) {
		for (int j = i + 1; ptr[j] != NULL; j++) {
			if (mx_strcmp(ptr[i], ptr[j]) > 0) {
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
}
