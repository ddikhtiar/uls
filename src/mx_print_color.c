#include "uls.h"

static void sx_print_color(const char *str);

void mx_print_color(t_data *node) {
    if (MX_ISSOCK(node->buffer->st_mode)) {
        mx_printstr(ANSI_COLOR_GREEN);
        sx_print_color(node->name);
    }
    else if (S_ISVTX & node->buffer->st_mode) {
        mx_printstr("\033[30;42m");
        sx_print_color(node->name);
    }
    else if (MX_ISCHR(node->buffer->st_mode)) {
        mx_printstr("\033[34;43m");
        sx_print_color(node->name);
    }
    else if (MX_ISBLK(node->buffer->st_mode)) {
        mx_printstr("\033[34;46m");
        sx_print_color(node->name);
    }
    else if (MX_ISFIFO(node->buffer->st_mode)) {
        mx_printstr(ANSI_COLOR_YELLOW);
        sx_print_color(node->name);
    }
    else if (MX_ISDIR(node->buffer->st_mode)) {
        mx_printstr(ANSI_COLOR_BLUE);
        sx_print_color(node->name);
    }
    else if (MX_ISLNK(node->buffer->st_mode)) {
        mx_printstr(ANSI_COLOR_MAGENTA);
        sx_print_color(node->name);
    }
    else if (MX_ISWHT(node->buffer->st_mode)) {
        mx_printstr("\033[36m");
        sx_print_color(node->name);
    }
    else if (MX_ISEXEC(node->buffer->st_mode)) {
        mx_printstr(ANSI_COLOR_RED);
        sx_print_color(node->name);
    }
    else if (MX_ISBIN(node->buffer->st_mode)) {
        mx_printstr(ANSI_COLOR_RED);
        sx_print_color(node->name);
    }
    else
        mx_printstr(node->name);
}

static void sx_print_color(const char *str) {
    mx_printstr(str);
    mx_printstr(ANSI_COLOR_RESET);
}
