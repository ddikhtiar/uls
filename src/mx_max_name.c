#include "uls.h"

int mx_max_name(t_data *list, int flg_G) {
    int current = 0;
    int max = 0;

    while (list) {
        current = mx_strlen(list->name);
        if (current > max)
            max = current;
        list = list->next;
    }
    if (flg_G == 1)
        max += 1;
    else
        max += (8 - (max % 8));
    return max;
}
