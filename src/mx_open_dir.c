#include "uls.h"

static bool sx_check_invis(int f_a, int f_A, const char *name);

void mx_open_dir(t_flags **flags, t_d_list **list) {
    t_d_list *ptr = *list;
    DIR *dirname = opendir(ptr->path->name);
    struct dirent *file = NULL;
    char *path = NULL;

    if (dirname == NULL && errno == 13)
        mx_push_data_back(&(ptr->link), mx_create_data(NULL, "Permission"));
    if (dirname != NULL) {
        while ((file = readdir(dirname)) != NULL) {
            if (sx_check_invis((*flags)->f_a, (*flags)->f_A, file->d_name))
                continue;
            path = mx_make_pathname(ptr->path->name, file->d_name);
            mx_push_data_back(&(ptr->link),
                              mx_create_data(path, file->d_name));
            mx_strdel(&path);
        }
    }
    if (dirname && closedir(dirname) < 0)
        exit(1);
}

static bool sx_check_invis(int f_a, int f_A, const char *name) {
    if (f_a == 0 && f_A == 0 && name[0] == '.')
        return true;
    if (f_a == 0 && f_A == 1 && mx_strcmp(name, ".") == 0)
        return true;
    if (f_a == 0 && f_A == 1 && mx_strcmp(name, "..") == 0)
        return true;
    return false;
}
