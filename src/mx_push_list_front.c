#include "uls.h"

void mx_push_list_front(t_d_list **list, t_data *data) {
    t_d_list *new = mx_create_list(data);
    t_d_list *first = *list;

    if (new) {
        new->next_list = first;
        *list = new;
    }
}
