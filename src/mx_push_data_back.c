#include "uls.h"

void mx_push_data_back(t_data **list, t_data *last) {
    t_data *ptr = *list;

    if (last == NULL)
        return;
    else if (*list == NULL)
        *list = last;
    else {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = last;
    }
}
