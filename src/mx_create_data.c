#include "uls.h"

t_data *mx_create_data(const char *path, const char *filename) {
    t_data *data = NULL;
    // t_stat stat;

    if (filename != NULL)
        data = (t_data*) malloc(sizeof(t_data));
	if (data) {
        data->name = mx_strdup(filename);
        data->buffer = mx_fill_buffer(path);
        data->next = NULL;
        // data->st_atimespec = data->buffer->st_atimespec;
        // data->st_mtimespec = data->buffer->st_mtimespec;
        // data->st_ctimespec = data->buffer->st_ctimespec;
        // data->st_btimespec = stat.st_btimespec;
    }
    return data;
}
