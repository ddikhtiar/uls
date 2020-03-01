#include "uls.h"

void mx_print_nlinks(t_data *current, int nspaces) {
    mx_printnchar(' ', nspaces - mx_intlength(current->buffer->st_nlink));
    mx_printint(current->buffer->st_nlink);
    mx_printchar(' ');
}
