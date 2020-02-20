#include "uls.h"

static void sx_print_files(t_data **list, int flg_G);

void mx_one_column_output(t_d_list *list, int flg_G, int input) {
    t_d_list *ptr = list;
    int size = mx_list_of_lists_size(&ptr);

    while (ptr) {
        if (size > 1 && ptr->path != NULL) {
            if (input != 1) {
                mx_printstr(ptr->path->name);
                mx_printstr(":\n");
            }
            else
                input = 0;
        }
        if (!mx_check_permission(ptr))
            mx_print_permission_denied(ptr);
        else
            sx_print_files(&(ptr->link), flg_G);
        ptr = ptr->next_list;
        if (ptr)
            mx_printchar('\n');
    }
}

static void sx_print_files(t_data **list, int flg_G) {
    t_data *ptr = *list;

    if (ptr) {
        while (ptr) {
            if (flg_G == 1)
                mx_print_color(ptr);
            else
                mx_printstr(ptr->name);
            mx_printchar('\n');
            ptr = ptr->next;
        }
    }
}
