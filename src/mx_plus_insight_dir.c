#include "uls.h"

void mx_plus_insight_dir(t_d_list **list) {
    t_d_list *ptr = *list;
    t_d_list *second = NULL;
    t_data *file = ptr->link;

    while (file != NULL) {
        if (MX_ISDIR(file->buffer->st_mode)) {
            if (mx_strcmp(file->name, ".") != 0
            || mx_strcmp(file->name, "..") != 0) {
                second = ptr->next_list;
                ptr->next_list = mx_create_list(file, NULL);
                ptr->next_list->next_list = second;
                ptr = ptr->next_list;
            }
        }
        file = file->next;
    }
}
