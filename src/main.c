#include "uls.h"

static void sx_print_arr(char **arr);

int main (int argc, char **argv) {
    char **flags = mx_flags_arr(argv);
    char **dirs = mx_dir_arr(argv);

    if (argc > 1) {
		mx_printstr("FLAGS:\n");
        sx_print_arr(flags);
		mx_printstr("\n========\n");
		mx_printstr("DIRS:\n");
		mx_check_arr_dir(&dirs);
		sx_print_arr(dirs);
        system("leaks uls");
    }
}

static void sx_print_arr(char **arr) {
    char **ptr = arr;

    while (*ptr) {
        mx_printstr(*ptr);
        mx_printchar('\n');
        ptr++;
    }
}
