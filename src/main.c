#include "uls.h"
 
static void sx_print_list(t_d_list *list);

int main (int argc, char **argv) {
    char **flags_names = mx_flags_arr(argc, argv);
    char **dirs_names = mx_dir_arr(argc, argv);
    t_flags *flags = mx_create_flags_struct(&flags_names);
    t_d_list *list = NULL;

    // if (argc == 1) {
    //     mx_basic_out(".");
    // }
    if (flags->illegal == 1)
        exit(1);
    if (mx_check_arr_dir(&dirs_names) == -1)
        exit(1);
    list = mx_list_full_assembly(&flags, &dirs_names);
    // sx_print_list(NULL);
    sx_print_list(list);
    // printf("--- Multicolumn output ---\n");
    // mx_mc_output(list);
    // system("leaks uls");
    //     exit(0);

// // check "| cat -e"
//     if(isatty(1)) printf ("is a character device\n");
//     else printf("is not a character device\n");

// // getting width of terminal
//     struct winsize sz;
//     ioctl(0, TIOCGWINSZ, &sz);
//     printf("Screen width: %i  Screen height: %i\n", sz.ws_col, sz.ws_row);
//     system("leaks uls");
}

static void sx_print_list(t_d_list *list) {
    t_d_list *ptr = list;
    t_data *current = NULL;

    if (!ptr)
        return;
    while (ptr) {
        current = ptr->link;
        mx_printstr("===(");
        if (ptr->path == NULL)
            mx_printstr("NULL");
        else
            mx_printstr(ptr->path->name);
        mx_printstr(")===\n");
        while (current) {
            mx_printstr(current->name);
            if (current->buffer == NULL)
                mx_printchar('#');
            mx_printstr(" -> ");
            if (current->next == NULL)
                mx_printstr("(NULL)\n");
            current = current->next;
        }
        mx_printstr("|\nV\n");
        if (ptr->next_list == NULL)
            mx_printstr("(NULL)\n");
        ptr = ptr->next_list;
    }
}
