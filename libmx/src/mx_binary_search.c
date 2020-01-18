#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int min = 0;
    int mid;
    int max = size - 1;

    *count = 0;
    while (min <= max) {
        *count += 1;
        mid = (min + max) / 2;
        if (mx_strcmp(arr[mid], s) == 0)
            return mid;
        else if (mx_strcmp(arr[mid], s) > 0)
            max = mid - 1;
        else
            min = mid + 1;
    }
    *count = 0;
    return -1;
}
