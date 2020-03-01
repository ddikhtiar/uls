#include "uls.h"

char *mx_make_pathname(const char *begin, const char *end) {
    char *step_one = NULL;
    char *step_two = NULL;

    if (mx_strcmp(begin, "/") != 0)
        step_one = mx_strjoin(begin, "/");
    else
        step_one = mx_strdup(begin);
    step_two = mx_strjoin(step_one, end);
    mx_strdel(&step_one);
    return step_two;
}
