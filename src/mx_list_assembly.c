#include "uls.h"

static void sx_plus_file_data(t_data **begin, t_data *end);

t_d_list *mx_list_assembly(t_flags **flags, char ***names) {
    char **ptr = *names;
    t_data *current = NULL;
    t_data *begin = NULL;
    t_d_list *list = NULL;
    t_d_list *dir = NULL;
    int indicate = 0;

    while (*ptr) {
        current = mx_create_data(*ptr);
        if (MX_ISREG(current->buffer->st_mode)) {
            sx_plus_file_data(&begin, current);
            if (indicate == 0) {
                mx_push_list_front(&list, begin);
                indicate = 1;
            }
        }
        if (MX_ISDIR(current->buffer->st_mode)) {
            dir = mx_create_list(current);
            mx_list_current_dir(flags, &dir);
            mx_push_list_back(&list, dir);
        }
        ptr++;
    }
    return list;
}

static void sx_plus_file_data(t_data **begin, t_data *data) {
    t_data *end = *begin;

    if (*begin == NULL) {
        *begin = data;
        return;
    }
    while (end->next != NULL)
        end = end->next;
    end->next = data;
}
