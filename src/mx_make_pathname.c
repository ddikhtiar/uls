#include "uls.h"

char *mx_make_pathname(const char *begin, const char *end) {
    char *step_one = NULL;
    char *step_two = NULL;

    step_one = mx_strjoin(begin, "/");
    step_two = mx_strjoin(step_one, end);
    mx_strdel(&step_one);
    return step_two;
}
