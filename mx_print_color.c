#include "uls.h"

static void sx_print_color(const char *color, const char *str) {
    mx_printstr(color);
    mx_printstr(str);
    mx_printstr(ANSI_COLOR_RESET);
}

static void sx_end_print(t_data *node) {
    if (MX_ISLNK(node->buffer->st_mode))
        sx_print_color(ANSI_COLOR_MAGENTA, node->name);
    else if (MX_ISWHT(node->buffer->st_mode))
        sx_print_color(ANSI_COLOR_ULTRA_BLUE, node->name);
    else if (MX_ISEXEC(node->buffer->st_mode))
        sx_print_color(ANSI_COLOR_RED, node->name);
    else if (MX_ISBIN(node->buffer->st_mode))
        sx_print_color(ANSI_COLOR_RED, node->name);
    else
        mx_printstr(node->name);
}

void mx_print_color(t_data *node) {
    if (MX_ISSOCK(node->buffer->st_mode))
        sx_print_color(ANSI_COLOR_GREEN, node->name);
    else if (MX_ISWRT(node->buffer->st_mode))
        sx_print_color(ANSI_COLOR_BLCK_ON_GRN, node->name);
    else if (MX_ISCHR(node->buffer->st_mode))
        sx_print_color(ANSI_COLOR_BLUE_ON_YLW, node->name);
    else if (MX_ISBLK(node->buffer->st_mode))
        sx_print_color(ANSI_COLOR_BLUE_ON_BLU, node->name);
    else if (MX_ISFIFO(node->buffer->st_mode))
        sx_print_color(ANSI_COLOR_YELLOW, node->name);
    else if (MX_ISDIR(node->buffer->st_mode))
        sx_print_color(ANSI_COLOR_BLUE, node->name);
    else
        sx_end_print(node);
}
