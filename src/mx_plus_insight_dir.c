#include "uls.h"

void mx_plus_insight_dir(t_d_list **list) {
    t_d_list *ptr = *list;
    t_d_list *some = ptr;
    t_d_list *second = NULL;
    t_data *file = ptr->link;
    char *start_path = NULL;
    char *full_path = NULL;

    while (file != NULL) {
        if (mx_strcmp(file->name, ".") == 0) {
            file = file->next;
            continue;
        }
        if (mx_strcmp(file->name, "..") == 0) {
            file = file->next;
            continue;
        }
        if (MX_ISDIR(file->buffer->st_mode)) {
            start_path = mx_strjoin(ptr->path->name, "/");
            full_path = mx_strjoin(start_path, file->name);
            second = some->next_list;
            some->next_list = mx_create_list(mx_create_data(full_path, full_path), NULL);
            some->next_list->next_list = second;
            some = some->next_list;
            mx_strdel(&start_path);
            mx_strdel(&full_path);
        }
        file = file->next;
    }
}
