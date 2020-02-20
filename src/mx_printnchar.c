#include "uls.h"

void mx_printnchar(char c, int n) {
    while (n) {
        write(1, &c, 1);
        n--;
    }
}

int mx_intlength(int n) {
    int result = 1;

    while (n / 10) {
        ++result;
        n /= 10;
    }
    return result;
}
