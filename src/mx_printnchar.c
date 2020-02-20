#include "uls.h"

void mx_printnchar(char c, int n) {
    while (n) {
        write(1, &c, 1);
        n--;
    }
}
