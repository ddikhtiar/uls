#include "uls.h"

void mx_sort_datas_list(t_flags **flags, t_d_list **list) {
    t_data *content = (*list)->link;

    mx_ascii_sort(&content);
    if ((*flags)->f_S == 1)
        mx_sort_size(&content);
    else {
        if ((*flags)->f_t == 1
            || (*flags)->f_l == 1) {
            if ((*flags)->f_u == 1)
                mx_sort_a_time(&content);
            if ((*flags)->f_c == 1)
                mx_sort_c_time(&content);
            if ((*flags)->f_t == 1
                && (*flags)->f_u == 0 && (*flags)->f_c == 0)
                mx_sort_m_time(&content);
        }
    }
    if ((*flags)->f_r == 1)
        mx_reverse_all(&content);
}