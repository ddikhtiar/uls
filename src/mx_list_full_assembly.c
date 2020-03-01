#include "uls.h"

static bool sx_is_dir(t_data *current, int flg_l) {
    if (MX_ISDIR(current->buffer->st_mode)
            || (MX_ISLNK(current->buffer->st_mode)
                && (flg_l == 0 || !mx_check_slash(current->name))))
        return true;
    else
        return false;
}

t_d_list *mx_list_full_assembly(t_flags **flags, char ***names) {
    t_d_list *list = NULL;
    t_data *files = NULL;
    t_data *current = NULL;
    char **arr_ptr = *names;

    while (*arr_ptr) {
        current = mx_create_data(*arr_ptr, *arr_ptr);
        if (sx_is_dir(current, (*flags)->f_l))
            mx_push_list_back(&list, mx_create_list(current, NULL));
        else {
            mx_push_data_back(&files, current);
            if (list == NULL || list->path != NULL)
                mx_push_list_front(&list, mx_create_list(NULL, files));
        }
        arr_ptr++;
    }
    mx_sort_lists_list(flags, &list);
    mx_for_dir_to_list(flags, &list);
    return list;
}
