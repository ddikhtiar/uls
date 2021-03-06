#include "uls.h"

void mx_swap_data(t_data *first, t_data *second) {
    struct stat *tmp_stat = NULL;
    char *tmp_name = NULL;
    char *tmp_path = NULL;
    char *tmp_symlink = NULL;

    tmp_stat = first->buffer;
    first->buffer = second->buffer;
    second->buffer = tmp_stat;
    tmp_name = first->name;
    first->name = second->name;
    second->name = tmp_name;
    tmp_path = first->d_path;
    first->d_path = second->d_path;
    second->d_path = tmp_path;
    tmp_symlink = first->symlink;
    first->symlink = second->symlink;
    second->symlink = tmp_symlink;
}
