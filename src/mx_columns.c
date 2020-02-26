#include "uls.h"

static int sx_col(unsigned int x, unsigned int size);

int mx_columns(int max_name, int list_size, int *ptr) {
    struct winsize sz;
    int window = 0;
    int column = 1;
    int x = 0;

    ioctl(0, TIOCGWINSZ, &sz);
    window = sz.ws_col;
    *ptr = window;
    x = window/max_name;
    if (x > 1) {
        if (x >= list_size)
            column = list_size;
        else
            column = sx_col(x, list_size);
    }
    return column;
}

static int sx_col(unsigned int x, unsigned int size) {
    unsigned int y = 0;

    while (x > 1) {
        y = size / x;
        if (y == 1 && (size % x > x / 2))
            return x;
        if (y >= 2) {
            if (x > 2 && size % x != 0 && size % (x - 1) == 0
                && y < (size % x))
                return (x - 1);
            else
                return x;
        }
        else
            x--;
    }
    return x;
}
