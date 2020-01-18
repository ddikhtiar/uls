#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    unsigned long nbr_copy = nbr;
    int len;
    int temp;
    char *hex = NULL;

    if (nbr == 0)
        return mx_strdup("0");
    for (len = 0; nbr_copy > 0; len++)
        nbr_copy /= 16;
    hex = mx_strnew(len);
    for (int i = len - 1; i >= 0; i--) {
        temp = nbr % 16;
        if (temp >= 0 && temp <= 9)
            hex[i] = temp + 48;
        else if (temp >= 10 && temp <= 15)
            hex[i] = temp + 87;
        nbr = nbr / 16;
    }
    return hex;
}
