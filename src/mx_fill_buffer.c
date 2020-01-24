#include "uls.h"

struct stat *mx_fill_buffer(const char *filename) {
    struct stat *buffer = malloc(sizeof(struct stat));
    int status;

    if (buffer != NULL) {
        status = stat(filename, buffer);
        if (status != 0) {
            free(buffer);
            return NULL;
        }
    }
    return buffer;
}
