#include "uls.h"

void mx_all_print(t_flags **flgs, t_d_list **list, int terminal, int quant) {
    if ((*flgs)->f_1 == 0 && (*flgs)->f_C == 0 && (*flgs)->f_l == 0) {
        if (terminal == 1)
            (*flgs)->f_C = 1;
        else
            (*flgs)->f_1 = 1;
    }
    if ((*flgs)->f_l == 1)
        mx_tbl_output(*list, (*flgs)->f_G, (*flgs)->f_T, quant);
    else if ((*flgs)->f_C == 1)
        mx_multicolumn_output(*list, (*flgs)->f_G, quant, terminal);
    else if ((*flgs)->f_1 == 1)
        mx_one_column_output(*list, (*flgs)->f_G, quant);
}
