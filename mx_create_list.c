#include "uls.h"

t_d_list *mx_create_list(t_data *pathname, t_data *data) {
    t_d_list *list = (t_d_list *) malloc(sizeof(t_d_list));

    if (!list)
        return NULL;
    list->path = pathname;
    list->link = data;
    list->next_list = NULL;
    return list;
}
