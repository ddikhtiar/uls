#include "uls.h"

void mx_swap_list(t_d_list *first, t_d_list *second) {
    t_data *tmp_link = NULL;
    t_data *tmp_path = NULL;

    tmp_path = first->path;
    first->path = second->path;
    second->path = tmp_path;
    tmp_link = first->link;
    first->link = second->link;
    second->link = tmp_link;
}
