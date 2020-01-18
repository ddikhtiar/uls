#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    char *result = NULL;
    int len_s1 = mx_strlen(s1);
    int len_s2 = mx_strlen(s2);

    if (s1 == NULL && s2 != NULL)
        result = mx_strdup(s2);
    if (s1 != NULL && s2 == NULL)
        result = mx_strdup(s1);
    if (s1 != NULL && s2 != NULL) {
        result = mx_strnew(len_s1 + len_s2);
        result = mx_strcpy(result, s1);
        result = mx_strcat(result, s2);
    }
    return result;
}
