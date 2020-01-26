#include "uls.h"

int main (int argc, char **argv) {
    char **flags_names = mx_flags_arr(argc, argv);
    char **dirs_names = mx_dir_arr(argc, argv);
    t_flags *flags = mx_create_flags_struct(flags_names);
    t_d_list *list = NULL;

    if (argc == 1) {
        mx_basic_out(".");
    }
    if (flags->illegal == 1)
        exit(0);
    if (mx_check_arr_dir(&dirs_name) == -1)
        exit(0);
    list = mx_list_assembly(&flags, &dirs_names);
        
}
