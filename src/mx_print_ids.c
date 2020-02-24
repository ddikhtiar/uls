#include "uls.h"

void mx_print_uid(t_data *current, int nspaces) {
    t_passwd *passwd = getpwuid(current->buffer->st_uid);
    int len;
    
    passwd ? mx_printstr(passwd->pw_name) : mx_printint(current->buffer->st_uid);
    len = passwd ? mx_strlen(passwd->pw_name) : mx_intlength(current->buffer->st_uid);
    mx_printnchar(' ', nspaces - len + 2);
}

void mx_print_gid(t_data *current, int nspaces) {
    t_group *group = getgrgid(current->buffer->st_gid);
    int len;

    group ? mx_printstr(group->gr_name) : mx_printint(current->buffer->st_gid);
    len = group ? mx_strlen(group->gr_name) : mx_intlength(current->buffer->st_gid);
    mx_printnchar(' ', nspaces - len + 2);
}
