#include "uls.h"

void mx_sort_lists_list(t_flags **flags, t_d_list **list) {
    if ((*flags)->f_f == 0) {
        mx_l_ascii_sort(list);
        if ((*flags)->f_S == 1)
            mx_l_sort_size(list);
        else {
            if ((*flags)->f_t == 1
                || (*flags)->f_l == 1) {
                if ((*flags)->f_u == 1)
                    mx_l_sort_a_time(list);
                if ((*flags)->f_c == 1)
                    mx_l_sort_c_time(list);
                if ((*flags)->f_t == 1
                    && (*flags)->f_u == 0 && (*flags)->f_c == 0)
                    mx_l_sort_m_time(list);
            }
        }
        if ((*flags)->f_r == 1)
            mx_l_reverse(list);
        mx_sort_datas_list(flags, list);
    }
}
