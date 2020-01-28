#include "uls.h"

void mx_list_current_dir(t_flags **flags, t_d_list **list) {
    t_d_list *list_ptr = *list;
    DIR *dirname = opendir(list_ptr->link->name );
    struct dirent *filename = NULL;
    char *str = NULL;
    char *str1 = NULL;

    while ((filename = readdir(dirname)) != NULL) {
        // if ((*flags)->f_A == 1) {
        //     if (mx_strcmp(filename->d_name, ".") == 0
        //     || mx_strcmp(filename->d_name, "..") == 0)
        //         continue;
        // }
        // if ((*flags)->f_a == 1 && filename->d_name[0] == '.')
        //     continue;
        
        if ((*flags)->illegal != 1) {
            str1 = mx_strjoin(list_ptr->link->name, "/");
            str = mx_strjoin(str1, filename->d_name);
            mx_push_data_back(&(list_ptr->link), str);
            mx_strdel(&str1);
            mx_strdel(&str);
        }
    }
    if (closedir(dirname) < 0)
        exit(1);
}
