#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *result;
    size_t len = 0;

    if (size == 0 && ptr) {
        free(ptr);
        return NULL;
    }
    if (size && !ptr)
        return malloc(size);
    len = mx_strlen(ptr);
    if (len > size)
        size = len;
    result = malloc(size);
    if (result == NULL)
        return NULL;
    result = mx_memmove(result, ptr, size);
    return result;
}
