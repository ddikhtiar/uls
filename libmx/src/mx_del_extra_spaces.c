#include "libmx.h"

static void how_long_str(int *len, const char *str);

char *mx_del_extra_spaces(const char *str) {
    char *new = mx_strtrim(str);
    char *result = NULL;
    int len = mx_strlen(new);
    int jump = 0;

    if (str == NULL)
        return NULL;
    how_long_str(&len, new);
    result = mx_strnew(len);
    for (int i = 0; i < len; i++) {
        if (mx_isspace(new[i + jump])) {
            new[i + jump] = ' ';
            while (mx_isspace(new[i + 1 + jump]))
                jump++;
        }
        result[i] = new[i + jump];
    }
    result[len] = '\0';
    mx_strdel(&new);
    return result;
}

static void how_long_str(int *len, const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i]) && mx_isspace(str[i + 1]))
            (*len)--;
    }
}
