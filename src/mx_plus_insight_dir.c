#include "uls.h"

static bool sx_stop_segfault(const char *str);

void mx_plus_insight_dir(t_d_list **list) {
    t_d_list *ptr = *list;
    t_d_list *som = ptr;
    t_d_list *second = NULL;
    char *path = NULL;

    for (t_data *file = ptr->link; file != NULL; file = file->next) {
        if (!sx_stop_segfault(file->name))
            continue;
        if (MX_ISDIR(file->buffer->st_mode)) {
            path = mx_make_pathname(ptr->path->name, file->name);
            second = som->next_list;
            som->next_list = mx_create_list(mx_create_data(path, path), NULL);
            som->next_list->next_list = second;
            som = som->next_list;
            mx_strdel(&path);
        }
    }
}

static bool sx_stop_segfault(const char *str) {
    if (mx_strcmp(str, ".") == 0)
        return false;
    if (mx_strcmp(str, "..") == 0)
        return false;
    if (mx_strcmp(str, "Permission") == 0)
        return false;
    return true;
}
