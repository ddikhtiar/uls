#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int len_h = mx_strlen(haystack);
    int len_n = mx_strlen(needle);

    if (len_h < len_n)
        return NULL;
    if (!len_n)
        return (char *) haystack;
    for (; (haystack = mx_strchr(haystack, needle[0])) != NULL; haystack++) {
        if (!mx_strncmp(haystack, needle, len_n))
            return (char *) haystack;
    }
    return NULL;
}
