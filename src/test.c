#include "uls.h"
#include <stdio.h>

int main (int argc, char **argv) {
	char **files = NULL;
	char **f_ptr = NULL;

	if (argc > 1) {
		files = mx_arr_filenames(argv[1]);
		f_ptr = files;
		while (*f_ptr) {
			if (**f_ptr != '.')
			printf("%s\n", *f_ptr);
			f_ptr++;
		}
	}
}
