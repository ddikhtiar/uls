#include "uls.h"

void mx_print_major(t_data *current, int nspaces) {
    int major = MX_MAJOR(current->buffer->st_rdev);

    mx_printnchar(' ', nspaces - mx_intlength(MX_MAJOR(current->buffer->st_rdev)));
    mx_printint(major);
    mx_printstr(", ");
}

// major and minor or not
void mx_out_mjmn(t_data *current, int *size) {
    if (MX_ISCHR(current->buffer->st_mode) ||
        MX_ISBLK(current->buffer->st_mode)) {
        mx_print_major(current, 3);
        mx_print_minor(current, 3);
    } else {
        mx_print_size(current, size[3]);
    }
}
