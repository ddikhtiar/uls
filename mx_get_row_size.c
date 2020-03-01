#include "uls.h"

static void *mx_memalloc(size_t size);

int *mx_get_row_size(t_data *current) {
    struct group *gr = getgrgid(current->buffer->st_gid);
    int *size = mx_memalloc(4 * sizeof(int));
    bool majorminor = false;

    while (current) {
        (MX_ISCHR(current->buffer->st_mode) || MX_ISBLK(current->buffer->st_mode)) 
            ? majorminor = true : 0;
        gr = getgrgid(current->buffer->st_gid);
        size[0] = MX_MAX(mx_intlength(current->buffer->st_nlink), size[0]);
        size[1] = MX_MAX(mx_strlen(getpwuid(current->buffer->st_uid)->pw_name), size[1]);
        size[2] = gr ? MX_MAX(mx_strlen(gr->gr_name), size[2])
                     : MX_MAX(mx_intlength(current->buffer->st_gid), size[2]);
        size[3] = MX_MAX(mx_long_length(current->buffer->st_size), size[3]);
        current = current->next;
    }
    if (majorminor)
        size[3] = size[3] < 8 ? 8 : size[3];
    return size;
}

static void *mx_memalloc(size_t size) {
    size_t i;
    char *str;

    if ((str = (char *)malloc(size)) == NULL)
        return (NULL);
    i = -1;
    while (++i < size)
        str[i] = 0;
    return (str);
}
