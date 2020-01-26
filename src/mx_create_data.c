#include "uls.h"

t_data *mx_create_data(const char *filename) {
    t_data *data = NULL;

    if (filename)
        data = (t_data*) malloc(sizeof(t_data));
	if (data) {
        data->name = mx_strdup(filename);
        data->buffer = mx_fill_buffer(filename);
        if (data->buffer == NULL)
            return NULL;
        data->next = NULL;
    }
    return data;
}
