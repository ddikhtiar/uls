#include "uls.h"

void mx_l_sort_size(t_d_list **list) {
    t_d_list *ptr1 = *list;
    t_d_list *ptr2 = NULL;

    if (ptr1->path == NULL)
        ptr1 = ptr1->next_list;
    if (!ptr1)
        return;
    while (ptr1->next_list != NULL) {
        ptr2 = ptr1->next_list;
        while (ptr2) {
            if (ptr1->path->buffer->st_size < ptr2->path->buffer->st_size)
                mx_swap_list(ptr1, ptr2);
            ptr2 = ptr2->next_list;
        }
    ptr1 = ptr1->next_list;
    }
}
