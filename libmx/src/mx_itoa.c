#include "libmx.h"

char *mx_itoa(int number) {
    int x_copy = 0;
    int minus = 0;
    int len = 0;
    char *str = NULL;

    if (number < 0) {
        minus = 1;
        number *= -1;
    }
    x_copy = number;
    for (; x_copy > 0; len++)
        x_copy = x_copy / 10;
    str = mx_strnew(len + minus + 1);
    for (int i = len + minus - 1; i >= minus; i--) {
        str[i] = number % 10 + 48;
        number /= 10;
    }
    if (minus == 1)
        str[0] = '-';
    return str;
}
