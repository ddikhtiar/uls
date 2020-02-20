#include "uls.h"

int mx_list_of_lists_size(t_d_list **list) {
    t_d_list *ptr = *list;
    int size = 0;

    if (ptr != NULL) {
        while (ptr) {
            size++;
            ptr = ptr->next_list;
        }
    }
    return size;
}
