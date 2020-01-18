#include "libmx.h"

char *mx_strtrim(const char *str) {
    int len = mx_strlen(str);
    int begin = 0;
    int end = 0;

    if (str == NULL)
        return NULL;
    for (; mx_isspace(str[begin]); begin++);
    if (begin >= len)
        return mx_strdup("");
    for (; mx_isspace(str[len - 1 - end]) && end < len; end++);
    return mx_strndup((str + begin), len - begin - end);
}
