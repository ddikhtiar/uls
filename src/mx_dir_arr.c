#include "uls.h"

char **mx_dir_arr(char **arr) {
	char **arr_ptr = arr + 1;
	char **dirs = NULL;
	int num_dirs = mx_number_of_dir(arr_ptr);

	if (num_dirs != 0) {
		dirs = (char **) malloc(sizeof(char *) * (num_dirs + 1));
		while (**arr_ptr == '-')
			arr_ptr++;
		for (int i = 0; i < num_dirs; i++) {
			dirs[i] = mx_strdup(*arr_ptr);
			arr_ptr++;
		}
		dirs[num_dirs] = NULL;
	}
	return dirs;
}
