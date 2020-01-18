#include "uls.h"

char **mx_arr_filenames(const char *dir_name) {
	DIR *current = opendir(dir_name);
	char **arr_filenames = NULL;
	int quantity = 0;
	struct dirent *filename = NULL;

	if (current == NULL)
		return NULL;
	while ((filename = readdir(current)) != NULL)
		quantity++;
	if (quantity == 0)
		return NULL;
	filename = NULL;
	rewinddir(current);
	arr_filenames = (char **) malloc(sizeof(char *) * (quantity + 1));
	for (int i = 0; (filename = readdir(current)) != NULL; i++)
		arr_filenames[i] = mx_strdup(filename->d_name);
	arr_filenames[quantity] = NULL;
	if (closedir(current) < 0)
		return NULL;
	return arr_filenames;
}
