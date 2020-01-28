#include "uls.h"

// static void sx_print_arr(char ***arr_str);
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
    list = mx_list_assembly(&flags, &dirs_names);
    sx_print_list(list);
    // system("leaks uls");
}

static void sx_print_list(t_d_list *list) {
    t_d_list *ptr = list;
    t_data *current = NULL;

    if (!ptr)
        return;
    while (ptr) {
        current = ptr->link;
        while (current) {
            mx_printstr(current->name);
            if (current->buffer == NULL)
                mx_printchar('*');
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

// static void sx_print_arr(char ***arr_str) {
//     char **ptr = *arr_str;

//     if (!ptr)
//         return;
//     while (*ptr) {
//         mx_printstr(*ptr);
//         mx_printchar('\n');
//         ptr++;
//     }
// }
