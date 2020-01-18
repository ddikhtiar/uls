#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;

    if (!str || !sub)
        return -1;
    for (int i = 0; str[i] != '\0'; i++) {
        int j = 0;

        while (str[i] == sub[j] && sub[j] != '\0') {
            i++;
            j++;
        }
        if (sub[j++] == '\0') {
            count++;
            i--;
        }
    }
    return count;
}
