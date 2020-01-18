#include "libmx.h"

int mx_list_size(t_list *list) {
    int counter = 0;
    t_list *copy_list = list;

    while (copy_list != NULL) {
        counter++;
        copy_list = copy_list->next;
    }
    return counter;
}
