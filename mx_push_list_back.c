#include "uls.h"

void mx_push_list_back(t_d_list **list, t_d_list *last) {
    t_d_list *ptr = *list;

    if (!last)
        return;
    else if (*list == NULL)
        *list = last;
    else {
        while (ptr->next_list != NULL)
            ptr = ptr->next_list;
        ptr->next_list = last;
    }
}
