#include "uls.h"

void mx_swap_data(t_data **first, t_data **second) {
    t_data *f_tail = (*first)->next;
    t_data *s_tail = (*second)->next;
    t_data *tmp = NULL;

    (*first)->next = NULL;
    (*second)->next = NULL;
    tmp = *first;
    *first = *second;
    *second = tmp;
    (*first)->next = s_tail;
    (*second)->next = f_tail;
}
