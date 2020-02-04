#include "uls.h"

void mx_for_dir_to_list(t_flags **flags, t_d_list **list) {
    t_d_list *ptr = *list;
    t_flags *flg = *flags;

    while (ptr != NULL) {
        if (ptr->path != NULL) {
            mx_open_dir(&ptr);
        }
    }
}