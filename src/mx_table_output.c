#include "uls.h"

void mx_tbl_output(t_d_list *list) {
	t_d_list *ptr = list;
	t_data *current = NULL;
	current = ptr->link;
	t_passwd *passwd = getpwuid(current->buffer->st_uid);
	t_group *group = getgrgid(current->buffer->st_gid);
    time_t *t;

    while(ptr){
        current = ptr->link;
        mx_printstr(ptr->path->name);
        mx_printstr(":\n");
	    mx_print_total_nblocks(current);
        while(current) {
            t = &(current->buffer->st_mtimespec.tv_sec);
            mx_print_chmod(current, 1, current->d_path);
            mx_printint(current->buffer->st_nlink);
            mx_printstr(" ");
            mx_printstr(passwd->pw_name);
            mx_printstr(" ");
            if(group == NULL) {
                mx_printint(current->buffer->st_gid);
            } else {
                mx_printstr(group->gr_name);
            }
            mx_printstr(" ");
            if (MX_ISCHR(current->buffer->st_mode) || MX_ISBLK(current->buffer->st_mode)) {
                mx_print_major(current, 3);
                mx_print_minor(current, 3);
            } else {
                mx_printint(current->buffer->st_size);
            }
            mx_printstr(" ");
            mx_print_time(t);
            // mx_printstr(" ");
            mx_printstr(current->name);
            mx_printstr("\n");
            current = current->next;
        }
        ptr = ptr->next_list;
    }
}

static char get_file_acl(char *path) {
    acl_t tmp;

    if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
        return ('@');
    if ((tmp = acl_get_file(path, ACL_TYPE_EXTENDED))) {
        acl_free(tmp);
        return ('+');
    }
    return (' ');
}

static char get_file_type(t_data *current) {
    if (MX_ISREG(current->buffer->st_mode))
        return ('-');
    else if (MX_ISDIR(current->buffer->st_mode))
        return ('d');
    else if (MX_ISLNK(current->buffer->st_mode))
        return ('l');
    else if (MX_ISBLK(current->buffer->st_mode))
        return ('b');
    else if (MX_ISCHR(current->buffer->st_mode))
        return ('c');
    else if (MX_ISSOCK(current->buffer->st_mode))
        return ('s');
    else if (MX_ISFIFO(current->buffer->st_mode))
        return ('p');
    else
        return ('-');
}

void mx_print_chmod(t_data *current, int space_num, char *path) {
    char chmod[12];

    chmod[0] = get_file_type(current);
    chmod[1] = (S_IRUSR & current->buffer->st_mode) ? 'r' : '-';
    chmod[2] = (S_IWUSR & current->buffer->st_mode) ? 'w' : '-';
    chmod[3] = (S_IXUSR & current->buffer->st_mode) ? 'x' : '-';
    chmod[4] = (S_IRGRP & current->buffer->st_mode) ? 'r' : '-';
    chmod[5] = (S_IWGRP & current->buffer->st_mode) ? 'w' : '-';
    chmod[6] = (S_IXGRP & current->buffer->st_mode) ? 'x' : '-';
    chmod[7] = (S_IROTH & current->buffer->st_mode) ? 'r' : '-';
    chmod[8] = (S_IWOTH & current->buffer->st_mode) ? 'w' : '-';
    chmod[9] = (S_IXOTH & current->buffer->st_mode) ? 'x' : '-';
    chmod[10] = get_file_acl(path);
    chmod[11] = '\0';
    S_ISUID & current->buffer->st_mode ? (chmod[3] = chmod[3] == '-' ? 'S' : 's') : 0;
    S_ISGID & current->buffer->st_mode ? (chmod[6] = chmod[6] == '-' ? 'S' : 's') : 0;
    S_ISVTX & current->buffer->st_mode ? (chmod[9] = chmod[9] == '-' ? 'T' : 't') : 0;
    mx_printstr(chmod);
    mx_printnchar(' ', space_num);
}
