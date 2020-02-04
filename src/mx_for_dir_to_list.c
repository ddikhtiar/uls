#include "uls.h"

void mx_for_dir_to_list(t_flags **flags, t_d_list **list) {
    t_d_list *ptr = *list;

    while (ptr != NULL) {
        if (ptr->path != NULL) {
            mx_open_dir(flags, &ptr);
//            mx_sort_list(flags, &ptr);
            if ((*flags)->f_R == 1)
                mx_plus_insight_dir(flags, &ptr);
        }
        ptr = ptr->next_list;
    }
}
