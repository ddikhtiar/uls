#include "uls.h"

t_d_list *mx_create_list(const char *dirname, t_data *data) {
    t_d_list *list = (t_d_list *) malloc(sizeof(t_d_list));

    if (!list)
        return NULL;
    list->path = dirname;
    list->link = data;
    list->next_list = NULL;
    return list;
}
