#include "uls.h"

static int sx_size_list (t_d_list **list) {
    t_d_list *ptr = *list;
    int result = 0;

    if (ptr) {
        for (; ptr != NULL; ptr = ptr->next_list)
            result++;
    }
    return result;
}

static t_d_list *sx_node_with_num(t_d_list *list, int num) {
    t_d_list *ptr = list;

    for (; num > 0; num--)
        ptr = ptr->next_list;
    return ptr;
}

void mx_l_reverse(t_d_list **list) {
    t_d_list *ptr = *list;
    t_d_list *one = NULL;
    t_d_list *two = NULL;
    int size = 0;

    if (ptr->path == NULL)
        ptr = ptr->next_list;
    if (!ptr)
        return;
    size = sx_size_list(&ptr);
    for (int i = 0; i < (size / 2); i++) {
        one = sx_node_with_num(ptr, i);
        two = sx_node_with_num(ptr, size -1 - i);
        mx_swap_list(one, two);
    }
}
