#include "uls.h"

int main (int argc, char **argv) {
//	char **dirs = NULL;
	char **flags = NULL;
	t_flags *f = NULL;

	if (argc > 1) {
		flags = mx_flags_arr(argv);
//		dirs = mx_dir_arr(argv);
		f = mx_create_flags_struct(&flags);
		if (f->illegal == 0) {
			mx_printint(f->f_l);
			mx_printchar('\n');
        }
	}
}
