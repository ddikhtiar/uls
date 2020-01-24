#include "uls.h"

static void sx_print_arr(char **arr);

int main (int argc, char **argv) {
    char **flags = NULL;
    char **dirs = NULL;

    if (argc > 1) {
        
        system("leaks uls");
    }
}

static void sx_print_arr(char **arr) {
    char **ptr = arr;

    while (*ptr) {
        mx_printstr(*ptr);
        mx_printchar('\n');
        ptr++;
    }
}
