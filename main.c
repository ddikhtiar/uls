#include "uls.h"

int main (int argc, char **argv) {
    char **flags_names = mx_flags_arr(argc, argv);
    char **dirs_names = mx_dir_arr(argc, argv);
    t_flags *flags = mx_create_flags_struct(&flags_names);
    t_d_list *list = NULL;
    int x = 0;
    
    if (flags->illegal == 1)
        exit(1);
    if (mx_check_arr_dir(&dirs_names) == -1)
        exit(1);
    x = mx_number_of_dir(dirs_names);
    list = mx_list_full_assembly(&flags, &dirs_names);
    if (isatty(1) == 0)
        flags->f_G = 0;
    mx_all_print(&flags, &list, isatty(1), x);
    // system("leaks uls");
    exit(0);
}
