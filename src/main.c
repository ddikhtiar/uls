#include "uls.h"
#include <stdio.h>

static void sx_print_arr(char **arr);

int main (int argc, char **argv) {
    char **flags = mx_flags_arr(argc, argv);
    char **dirs = mx_dir_arr(argc, argv);
    t_data *data = NULL;

//    if (argc > 1) {
		mx_printstr("FLAGS:\n");
        sx_print_arr(flags);
		mx_printstr("\n========\n");
		mx_printstr("DIRS:\n");
		mx_check_arr_dir(&dirs);
		sx_print_arr(dirs);
		if (!dirs)
			exit(0);
        data = mx_create_data(dirs[0]);
		printf("\nData generated\n");
        if (data != NULL && MX_ISDIR(data->buffer->st_mode))
			mx_printstr("Struct work\n");
      system("leaks uls");
//    }
}

static void sx_print_arr(char **arr) {
    char **ptr = arr;

	if (!arr)
		return;
    while (*ptr) {
        mx_printstr(*ptr);
        mx_printchar('\n');
        ptr++;
    }
}
