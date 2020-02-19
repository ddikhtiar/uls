#include "uls.h"

bool mx_check_permission(t_d_list *list) {
    t_data *first = list->link;

    if (first->buffer == NULL && mx_strcmp(first->name, "Permission") == 0)
        return false;
    else
        return true;
}
