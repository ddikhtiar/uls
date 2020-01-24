#include "uls.h"

t_data *mx_create_data(char *filename) {
    t_data *data = NULL;

    if (filename)
        data = (t_data*) malloc(sizeof(t_data));
	if (data == NULL)
        return NULL;
	else {
        data->name = mx_strdup(filename);
        data->buffer = mx_fill_buffer(filename);
        data->next = NULL;
    }
    return data;
}
