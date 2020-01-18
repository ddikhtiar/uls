#ifndef ULS_H
#define ULS_H

#include "../libmx/inc/libmx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int mx_number_of_dir(char **arr);
int mx_number_of_flags(char **arr);
char **mx_dir_arr(char **arr);
char **mx_flags_arr(char **arr);
void mx_flags_out(char **arr);
char **mx_arr_filenames(const char *dir_name);

#endif
