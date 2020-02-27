#include "uls.h"

void mx_print_name(t_data *data, int flg_G) {
    if (flg_G == 1)
        mx_print_color(data);
    else
        mx_printstr(data->name);
}
