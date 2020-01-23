#include "uls.h"

t_data *mx_create_data(char *filename) {
	t_data *data = (t_data*)malloc(sizeof(t_data));
	data->file_name = (char*) malloc(sizeof(char) * (mx_strlen(filename) + 1));
	mx_strcpy(data->file_name, filename);

	return data;
}
