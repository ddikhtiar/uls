#include "uls.h"

void mx_push_list_front(t_d_list **list, t_d_list *first) {
    t_d_list *ptr = *list;

    if (!first)
        return;
    else if (*list == NULL)
        *list = first;
    else {
        first->next_list = ptr;
        *list = first; 
    }
}
