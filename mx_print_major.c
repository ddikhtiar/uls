#include "uls.h"

void mx_print_major(t_data *current, int nspaces) {
    int major = MX_MAJOR(current->buffer->st_rdev);

    mx_printnchar(' ', nspaces - mx_intlength(MX_MAJOR(current->buffer->st_rdev)));
    mx_printint(major);
    mx_printstr(", ");
}
