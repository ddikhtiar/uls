#include "uls.h"

int mx_size_data_list(t_data **data_list) {
    int result = 0;
    t_data *ptr = *data_list;

    if (ptr) {
        for (; ptr != NULL; ptr = ptr->next)
            result++;
    }
    return result;
}
