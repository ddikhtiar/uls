#include "uls.h"

void mx_swap_list(t_d_list **first, t_d_list **second) {
    t_d_list *temp = NULL;
    t_d_list *f_tail = (*first)->next_list;
    t_d_list *s_tail = (*second)->next_list;

    (*first)->next_list = NULL;
    (*second)->next_list = NULL;
    temp = *first;
    *first = *second;
    *second = temp;
    (*first)->next_list = s_tail;
    (*second)->next_list = f_tail;
}
