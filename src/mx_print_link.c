#include "uls.h"

void mx_print_link(t_data *current) {
    mx_printstr(" -> ");
    mx_printstr(current->symlink);
}
