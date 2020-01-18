#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *jumper = *list;

    while (jumper->next != NULL)
        jumper = jumper->next;
    jumper->next = mx_create_node(data);
}
