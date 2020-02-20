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
    // mx_all_print(&flags, &list, isatty(1), x);
    // mx_one_column_output(list, flags->f_G, x);
    // mx_mc_output(list);
    mx_tbl_output(list);
    // system("leaks uls");
    // exit(0);
}
