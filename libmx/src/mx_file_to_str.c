#include "libmx.h"

static int len_file(const char *filename);

char *mx_file_to_str(const char *filename) {
    int fd;
    int lenght = len_file(filename);
    char *str = NULL;
    char buf[1];

    if (lenght < 0)
        return NULL;
    if ((fd = open(filename, O_RDONLY)) < 0)
        return NULL;
    str = mx_strnew(lenght);
    for (int i = 0; read(fd, buf, 1); i++) {
        str[i] = buf[0];
    }
    str[lenght] = '\0';
    if (close (fd) < 0) {
        mx_strdel(&str);
        return NULL;
    }
    return str;
}

static int len_file(const char *file) {
    int fd;
    int len = 0;
    char buf[1];

    if (file == NULL)
        return -1;
    if ((fd = open(file, O_RDONLY)) < 0)
        return -1;
    while (read(fd, buf, 1)) {
        len++;
    }
    if (close(fd) < 0)
        return -1;
    return len;
}
