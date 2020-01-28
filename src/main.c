#include "uls.h"

static void sx_print_arr(char ***arr_str);

int main (int argc, char **argv) {
    char **flags_names = mx_flags_arr(argc, argv);
    char **dirs_names = mx_dir_arr(argc, argv);
    t_flags *flags = mx_create_flags_struct(&flags_names);
    // t_d_list *list = NULL;

    // if (argc == 1) {
    //     mx_basic_out(".");
    // }
    if (flags->illegal == 1)
        exit(0);
    if (mx_check_arr_dir(&dirs_names) == -1)
        exit(0);
    mx_printstr("FLAGS:");
    mx_printchar('\n');
    sx_print_arr(&flags_names);
    mx_printstr("DIRECTORIES:");
    mx_printchar('\n');
    sx_print_arr(&dirs_names);
    // list = mx_list_assembly(&flags, &dirs_names);

// check "| cat -e"
    if(isatty(1)) printf ("is a character device\n");
    else printf("is not a character device\n");

// getting width of terminal
    struct winsize sz;
    ioctl(0, TIOCGWINSZ, &sz);
    printf("Screen width: %i  Screen height: %i\n", sz.ws_col, sz.ws_row);
   
    system("leaks uls");
}

static void sx_print_arr(char ***arr_str) {
    char **ptr = *arr_str;

    if (!ptr)
        return;
    while (*ptr) {
        mx_printstr(*ptr);
        mx_printchar('\n');
        ptr++;
    }
}
