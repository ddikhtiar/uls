#include "uls.h"

static unsigned int num_length(long long int number) {
    unsigned int length = 0;

    while (number) {
        number /= 10;
        length++;
    }
    return length;
}

void mx_print_size(t_data *current, int nspaces) {
    char *size = NULL;

    size = mx_lltoa(current->buffer->st_size);
    mx_printnchar(' ', nspaces - mx_long_length(current->buffer->st_size));
    mx_printstr(size);
    mx_strdel(&size);
    mx_printchar(' ');
}

char *mx_lltoa(long long int number) {
    unsigned int length = num_length(number);

    long long int tmp = number;
    char *result = NULL;

    result = mx_strnew(length);
    if (number == 0)
        return mx_strcpy(result, "0");
    if (number == -9223372036854775807)
        return mx_strcpy(result, "-9223372036854775807");
    for (unsigned int i = 0; i < length; i++) {
        if (tmp < 0) {
            result[length] = '-';
            tmp = -tmp;
        }
        result[i] = (tmp % 10) + '0';
        tmp /= 10;
    }
    mx_str_reverse(result);
    return result;
}
