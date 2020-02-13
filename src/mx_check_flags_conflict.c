#include "uls.h"

void mx_check_flags_conflict(t_flags **flags) {
    t_flags *flg = *flags;

    if (flg->f_l == 0)
        flg->f_T = 0;
    if (flg->f_t == 0 && flg->f_l == 0) {
        flg->f_c = 0;
        flg->f_u = 0;
    }
    if (flg->f_f == 1)
        flg->f_a = 1;
}
