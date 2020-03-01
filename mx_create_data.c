#include "uls.h"

t_data *mx_create_data(char *path, char *filename) {
    t_data *data = NULL;

    if (filename != NULL)
        data = (t_data*) malloc(sizeof(t_data));
    if (data) {
        data->name = mx_strdup(filename);
        data->buffer = mx_fill_buffer(path);
        data->next = NULL;
        data->d_path = mx_strdup(path);
        if (MX_ISLNK(data->buffer->st_mode)) {
            readlink(data->d_path, data->symlink, NAME_MAX);
        }
    }
    return data;
}
