#include "libmx.h"

static void make_replace(const char **str, const char **sub,
const char **replace, char **r);

char *mx_replace_substr(const char *str, const char *sub,
const char *replace) {
    int count = mx_count_substr(str, sub);
    const char *str_p = str;
    char *r1 = NULL;
    char *r2 = NULL;
    int len = 0;

    if (str != NULL && sub != NULL && replace != NULL) {
        if (count == 0)
            return mx_strdup(str);
        len = mx_strlen(str) - count * (mx_strlen(sub) - mx_strlen(replace));
        r1 = mx_strnew(len);
        r2 = r1;
        make_replace(&str_p, &sub, &replace, &r2);
        return r1;
    }
    return NULL;
}

static void make_replace(const char **str, const char **sub,
const char **replace, char **r) {
    const char *st = *str;
    const char *su = *sub;
    const char *rep = *replace;
    char *new = *r;

    while (*st != '\0') {
        if (st != mx_strstr(st, su))
            *new++ = *st++;
        else {
            new = mx_strncpy(new, rep, mx_strlen(rep));
            new += mx_strlen(rep);
            st += mx_strlen(su);
        }
    }
}
