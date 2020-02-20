#include "uls.h"

static void sx_print_files(t_data **list);

void mx_one_column_output(t_d_list **list) {
    t_d_list *ptr = *list;
    int size = mx_list_of_lists_size(&ptr);

    while (ptr) {
        if (size > 1 && ptr->path != NULL) {
            mx_printstr(ptr->path->name);
            mx_printstr(":\n");
        }
        if (!mx_check_permission(ptr))
            mx_print_permission_denied(ptr);
        else
            sx_print_files(&(ptr->link));
        ptr = ptr->next_list;
        if (ptr)
            mx_printchar('\n');
    }
}

static void sx_print_files(t_data **list) {
    t_data *ptr = *list;

    if (ptr) {
        while (ptr) {
            mx_printstr(ptr->name);
            mx_printchar('\n');
            ptr = ptr->next;
        }
    }
}
