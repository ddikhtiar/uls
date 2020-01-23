#include "uls.h"

int main (int argc, char **argv) {
	printf("argc = %d\n", argc);
	mx_get_filenames(argv[1]);
	// if (argc == 1)
	// 	mx_bacic_out();
	// else
	// 	mx_flags_out(argv);
	// exit(0);

// - - - - - test 1 BEGIN - - - - - - - - - - - 
// //	char **dirs = NULL;
// 	char **flags = NULL;
// 	t_flags *f = NULL;

// 	if (argc > 1) {
// 		flags = mx_flags_arr(argv);
// //	dirs = mx_dir_arr(argv);
// 		f = mx_create_flags_struct(&flags);
// 		if (f->illegal == 0) {
// 			mx_printint(f->f_l);
// 			mx_printchar('\n');
//         }
// 	}
// - - - - - test 1 END - - - - - - - - - - - - -
// - - - - - test 2 BEGIN - - - - - - - - - - - 

	// char *files = NULL;
	// char **f_ptr = NULL;

	// if (argc > 1) {
	// 	files = mx_get_filenames(argv[1]);
	// 	f_ptr = files;
	// 	while (*f_ptr) {
	// 		if (**f_ptr != '.')
	// 		printf("%s\n", *f_ptr);
	// 		f_ptr++;
	// 	}
	// }

// - - - - - test 2 END - - - - - - - - - - - - -
}
