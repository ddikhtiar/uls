#include "libmx.h"

static int count = 0;
static void check(char **arr, int *min, int *mid, int *max);
static void swap(char **arr, int min, int max, int *d);

int mx_quicksort(char **arr, int left, int right) {
    int min = left;
    int max = right;
    int mid = (min + max) / 2;

    if (arr == NULL)
        return -1;
    check(arr, &min, &mid, &max);
    if (left < max)
        mx_quicksort(arr, left, max);
    if (right > min)
        mx_quicksort(arr, min, right);
    return count;
}

static void check(char **arr, int *min, int *mid, int *max) {
    while (*min < *max) {
        if (mx_strlen(arr[*min]) < mx_strlen(arr[*mid]))
            (*min)++;
        if (mx_strlen(arr[*mid]) <= mx_strlen(arr[*max]))
            (*max)--;
        if (*min < *max)
            swap(arr, *min, *max, &count);
        (*min)++;
        (*max)--;
    }
}

static void swap(char **arr, int min, int max, int *d) {
    char *temp = NULL;
    int num = *d;

    temp = arr[min];
    arr[min] = arr[max];
    arr[max] = temp;
    num++;
    *d = num;
}
