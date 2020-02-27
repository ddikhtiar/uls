#include "uls.h"

static t_data *sx_pointer_shift(t_data *ptr, int edge) {    
    for (int i = 1; i <= edge; i++) {
        ptr = ptr->next;
        if (ptr == NULL)
            break;
    }
    return ptr;
}

static void sx_finally_print(t_data *list, int flg_G, int strings, int max) {
    t_data *ptr1 = NULL;
    t_data *ptr2 = NULL;
    int counter = strings;

    while (counter) {
        ptr1 = list;
        while (ptr1) {
            ptr2 = ptr1;
            mx_print_name(ptr2, flg_G);
            ptr1 = sx_pointer_shift(ptr1, strings);
            if (!ptr1) {
                mx_printchar('\n');
                break;
            }
            mx_print_spaces(ptr2->name, max);
        }
        list = list->next;
        counter--;
    }
}

static void sx_print_files(t_data *list, int flg_G) {
    int max = mx_max_name(list, flg_G);
    int list_size = mx_size_data_list(&list);
    int columns = mx_columns(max, list_size);
    int strings = list_size / columns;

    if (list_size % columns != 0)
        strings++;
    sx_finally_print(list, flg_G, strings, max);
}

void mx_multicolumn_output(t_d_list *list, int flg_G, int input) {
    int size = mx_list_of_lists_size(&list);

    while (list) {
        if (size > 1 && list->path != NULL) {
            if (input != 1) {
                mx_printstr(list->path->name);
                mx_printstr(":\n");
            }
            else
                input = 0;
        }
        if (!mx_check_permission(list))
            mx_print_permission_denied(list);
        else if (list->link != NULL)
            sx_print_files(list->link, flg_G);
        list = list->next_list;
        if (list)
            mx_printchar('\n');
    }
}
