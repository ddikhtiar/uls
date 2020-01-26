#include "uls.h"

void mx_push_list_back(t_d_list **first, t_d_list *list) {
    t_d_list *last = *first;

    if (!list)
        return;
    else if (*first == NULL)
        *first = list;
    else {
        while (last->next_list != NULL)
            last = last->next_list;
        last->next_list = list;
    }
}
