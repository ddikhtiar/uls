#include "uls.h"

void mx_sort_m_time(t_data **data_list) {
    t_data *ptr1 = *data_list;
    t_data *ptr2 = NULL;

    while (ptr1->next != NULL) {
        ptr2 = ptr1->next;
        while (ptr2) {
            if (ptr1->buffer->st_mtime < ptr2->buffer->st_mtime)
                mx_swap_data(ptr1, ptr2);
            if (ptr1->buffer->st_mtime == ptr2->buffer->st_mtime
                && mx_strcmp(ptr1->name, ptr2->name) > 0)
                mx_swap_data(ptr1, ptr2);
            ptr2 = ptr2->next;
        }
    ptr1 = ptr1->next;
    }
}
