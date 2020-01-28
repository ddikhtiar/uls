#include "uls.h"

t_data *mx_create_data(const char *filename) {
    t_data *data = NULL;

    if (filename != NULL)
        data = (t_data*) malloc(sizeof(t_data));
	if (data) {
        data->name = mx_strdup(filename);
        data->buffer = mx_fill_buffer(filename);
        data->next = NULL;
    }
    return data;
}
