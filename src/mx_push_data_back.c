#include "uls.h"

void mx_push_data_back(t_data **list, const char *filename) {
    t_data *data = mx_create_data(filename);
    t_data *last = NULL;

    if (!data)
        return;
    else if (*list == NULL)
        *list = data;
    else {
        last = *list;
        while (last->next != NULL)
            last = last->next;
        last->next = data;
    }
}
