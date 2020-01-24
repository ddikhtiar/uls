#include "uls.h"

int mx_number_of_dir(char **arr) {
	int num_dirs = 0;
	char **arr_ptr = arr;

	while (*arr_ptr && **arr_ptr == '-')
		arr_ptr++;
	while (*arr_ptr) {
		num_dirs++;
		arr_ptr++;
	}
	return num_dirs;
}
