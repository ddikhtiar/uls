#include "uls.h"

int mx_number_of_flags(char **arr) {
	int num_flgs = 0;
	char **arr_ptr = arr + 1;

	while (*arr_ptr && **arr_ptr == '-') {
		num_flgs++;
		arr_ptr++;
	}
	return num_flgs;
}
