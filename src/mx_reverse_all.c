#include "uls.h"

static t_data *sx_node_with_num(t_data *data_list, int num);

void mx_reverse_all(t_data **data_list) {
    int size = mx_size_data_list(data_list);
    t_data *ptr_list = *data_list;
    t_data *one = NULL;
    t_data *two = NULL;

    for (int i = 0; i < (size / 2); i++) {
        one = sx_node_with_num(ptr_list, i);
        two = sx_node_with_num(ptr_list, size -1 - i);
        mx_swap_data(one, two);
    }
}

static t_data *sx_node_with_num(t_data *data_list, int num) {
    t_data *ptr = data_list;

    for (; num > 0; num--)
        ptr = ptr->next;
    return ptr;
}
