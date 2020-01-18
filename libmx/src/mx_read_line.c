#include "libmx.h"

static int sx_find_line(char **s_buff, char **buff, char **lptr, char d);
static char *sx_cut_static_buff_before_index(char**static_buff, int index);
static int sx_check_static(char **static_buff, char **lineptr, char delim);
static int sx_return_static(char** lineptr, char**static_buff);

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    static char *static_buff = NULL;
    int i = 0;
    char *buff =NULL;

    if ((fd <= 0) || (buf_size <= 0) || (read(fd, NULL, 0) == -1))
        return -2;
    if (sx_check_static(&static_buff, lineptr, delim) == 1)
        return mx_strlen(*lineptr);
    buff = mx_strnew(buf_size);
    while ((i = read(fd, (void*)buff, buf_size)) > 0) {
        if ((mx_strchr((char*)buff, delim)) == NULL)
            mx_add_buff_to_static(&static_buff, &buff);
        else
            return sx_find_line(&static_buff, &buff, lineptr, delim);
    }
    mx_strdel(&buff);
    if (i == 0 && static_buff != NULL)
        return sx_return_static(lineptr, &static_buff);
    return -1;
}

static int sx_return_static(char** lineptr, char**static_buff) {
    int i = mx_strlen((*lineptr = mx_strdup(*static_buff)));

    mx_strdel(static_buff);
    return i;
}

static int sx_find_line(char **s_buff, char **buff, char **lptr, char d) {
    char *tmp = NULL;
    int index = mx_strchr_index(*buff, d);

    if (index > 0) {
        tmp = mx_strnew(index + 1);
        mx_strncpy(tmp, *buff, index);
    }
    *lptr = mx_strjoin(*s_buff, tmp);
    mx_strdel(s_buff);
    mx_strdel(&tmp);
    tmp = *buff;
    if (tmp != NULL && tmp[index + 1] != '\0')
        *s_buff = mx_strdup(&tmp[index + 1]);
    mx_strdel(buff);
    if (*lptr != NULL)
        return mx_strlen(*lptr);
    *lptr = mx_strdup("");
    return 0;
}

static char *sx_cut_static_buff_before_index(char **static_buff, int index) {
    char *tmp = NULL;
    char *str = *static_buff;

    if (*static_buff == NULL)
        return NULL;
    if (mx_strlen(*static_buff) == 0) {
        mx_strdel(static_buff);
        return NULL;
    }
    if (str[index + 1] == '\0') {
        mx_strdel(static_buff);
        return NULL;
    }
    tmp = mx_strdup(&str[index + 1]);
    mx_strdel(static_buff);
    return tmp;
}

static int sx_check_static(char **static_buff, char **lineptr, char delim) { 
    int index = mx_strchr_index(*static_buff, delim);
    char *tmp = NULL;

    if (index < 0)
        return 0;
    if (index == 0) {
        *static_buff = sx_cut_static_buff_before_index(static_buff, index);
        *lineptr = mx_strdup("");
        return 1;
    }
    tmp = mx_strnew(index);
    *lineptr = mx_strncpy(tmp, *static_buff, index);
    tmp = *static_buff;
    if (tmp[index + 1] != '\0') {
        *static_buff = mx_strdup(&tmp[index + 1]);
        mx_strdel(&tmp);
    }
    else
        mx_strdel(static_buff);
    return 1;
}
