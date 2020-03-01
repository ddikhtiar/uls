#include "uls.h"

static char *sx_short_name(const char *name) {
    char *result = (char *)name;
    int skip = mx_count_substr(name, "/");

    while (skip > 0) {
        if (*result == '/')
            skip--;
        result++;
    }
    return mx_strdup(result);
}

void mx_print_permission_denied(t_d_list *list) {
    char *name = NULL;

    name = sx_short_name(list->path->name);
    mx_printerr("uls: ");
    mx_printerr(name);
    mx_printerr(": Permission denied\n");
    mx_strdel(&name);
}
