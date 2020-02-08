#include "uls.h"

void mx_open_dir(t_flags **flags, t_d_list **list) {
    t_d_list *ptr = *list;
    DIR *dirname = opendir(ptr->path->name);
    struct dirent *file = NULL;
    char *path = NULL;

    while ((file = readdir(dirname)) != NULL) {
        if ((*flags)->f_a == 0 && (*flags)->f_A == 0
            && file->d_name[0] == '.')
            continue;
        if ((*flags)->f_A == 1 && mx_strcmp(file->d_name, ".") == 0)
            continue;
        if ((*flags)->f_A == 1 && mx_strcmp(file->d_name, "..") == 0)
            continue;
        path = mx_make_pathname(ptr->path->name, file->d_name);
        mx_push_data_back(&(ptr->link), mx_create_data(path, file->d_name));
        mx_strdel(&path);
    }
    if (closedir(dirname) < 0)
        exit(1);
}
