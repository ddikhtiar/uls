#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int len_sub = mx_strlen(sub);

    if (str == NULL || sub == NULL)
        return -2;
    for (int i = 0; str[i] != '\0'; i++) {
        char temp[len_sub + 1];

        for (int j = 0; j < len_sub; j++) {
            temp[j] = str[i + j];
            if (str[i + j] == '\0')
                return -1;
        }
        temp[len_sub] = '\0';
        if (mx_strcmp(temp, sub) == 0)
            return i;
    }
    return -1;
}
