#include "uls.h"

void mx_print_nlinks(t_data *current, int nspaces) {
    mx_printnchar(' ', nspaces - mx_intlength(current->buffer->st_nlink));
    mx_printint(current->buffer->st_nlink);
    // if ((flags & LS_O) && (flags & LS_G))
    //     mx_printnchar(' ', 3);
    // else
    mx_printchar(' ');
}
