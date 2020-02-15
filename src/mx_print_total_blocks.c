#include "uls.h"

void mx_print_total_nblocks(t_data *list) {
    t_data *ptr = list;
    char *total_str = NULL;
    int total = 0;

    while (ptr) {
        total += ptr->buffer->st_blocks;
        ptr = ptr->next;
    }
    mx_printstr("total ");
    total_str = mx_itoa(total);
    mx_printstr(total_str);
    mx_printchar('\n');
    mx_strdel(&total_str);
}
