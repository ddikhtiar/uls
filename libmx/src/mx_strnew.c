#include "libmx.h"

char *mx_strnew(const int size) {
    char *str = NULL;

    if (size < 0 || size > 2147483646)
        return NULL;
    else {
        str = (char*) malloc(sizeof(char) * (size + 1));
        if (str == NULL)
            return NULL;
        else {
            for (int i = 0; i <= size; i++)
                str[i] = '\0';
            return str;
        }
    }
}
