#include "uls.h"

static bool sx_check_slash(const char *str) {
    char *ptr = (char *)str;

    while (*(ptr + 1) != '\0')
        ptr++;
    return (*ptr == '/' ? false : true); 
}

char *mx_make_pathname(const char *begin, const char *end) {
    char *step_one = NULL;
    char *step_two = NULL;

    if (sx_check_slash(begin))
        step_one = mx_strjoin(begin, "/");
    else
        step_one = mx_strdup("/");
    step_two = mx_strjoin(step_one, end);
    mx_strdel(&step_one);
    return step_two;
}
