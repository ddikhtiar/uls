#include "uls.h"

void mx_tbl_output(t_d_list *list) {
	t_d_list *ptr = list;
	t_data *current = NULL;
	current = ptr->link;
	t_passwd *passwd = getpwuid(current->buffer->st_uid);
	t_group *group = getgrgid(current->buffer->st_gid);
    time_t *t;

	mx_print_total_nblocks(current);
	while(current) {
    	t = &(current->buffer->st_mtimespec.tv_sec);
    	mx_print_permission(current);
	    mx_printstr(" ");
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
		mx_printint(current->buffer->st_size);
		mx_printstr(" ");
		mx_print_time(t);
	    // mx_printstr(" ");
	    mx_printstr(current->name);
	    mx_printstr("\n");
		current = current->next;
	}
}

static char get_file_acl(t_data *current) {
    acl_t tmp;

    if (listxattr(current->full_path, NULL, 0, XATTR_NOFOLLOW) > 0)
        return ('@');
    if ((tmp = acl_get_file(current->full_path, ACL_TYPE_EXTENDED))) {
        acl_free(tmp);
        return ('+');
    }
    return (' ');
}
 
void mx_print_permission(t_data *cur_list) {
	mx_printstr( (S_ISDIR(cur_list->buffer->st_mode)) ? "d" : "-");
    mx_printstr( (cur_list->buffer->st_mode & S_IRUSR) ? "r" : "-");
    mx_printstr( (cur_list->buffer->st_mode & S_IWUSR) ? "w" : "-");
    mx_printstr( (cur_list->buffer->st_mode & S_IXUSR) ? "x" : "-");
    mx_printstr( (cur_list->buffer->st_mode & S_IRGRP) ? "r" : "-");
    mx_printstr( (cur_list->buffer->st_mode & S_IWGRP) ? "w" : "-");
    mx_printstr( (cur_list->buffer->st_mode & S_IXGRP) ? "x" : "-");
    mx_printstr( (cur_list->buffer->st_mode & S_IROTH) ? "r" : "-");
    mx_printstr( (cur_list->buffer->st_mode & S_IWOTH) ? "w" : "-");
    mx_printstr( (cur_list->buffer->st_mode & S_IXOTH) ? "x" : "-");
}

void mx_print_chmod(t_data *current, int space_num) {
    char chmod[12];

    chmod[0] = get_file_type(file);
    chmod[1] = (S_IRUSR & current->buffer->st_mode) ? 'r' : '-';
    chmod[2] = (S_IWUSR & current->buffer->st_mode) ? 'w' : '-';
    chmod[3] = (S_IXUSR & current->buffer->st_mode) ? 'x' : '-';
    chmod[4] = (S_IRGRP & current->buffer->st_mode) ? 'r' : '-';
    chmod[5] = (S_IWGRP & current->buffer->st_mode) ? 'w' : '-';
    chmod[6] = (S_IXGRP & current->buffer->st_mode) ? 'x' : '-';
    chmod[7] = (S_IROTH & current->buffer->st_mode) ? 'r' : '-';
    chmod[8] = (S_IWOTH & current->buffer->st_mode) ? 'w' : '-';
    chmod[9] = (S_IXOTH & current->buffer->st_mode) ? 'x' : '-';
    chmod[10] = get_file_acl(current);
    chmod[11] = '\0';
    S_ISUID & current->buffer->st_mode ? (chmod[3] = chmod[3] == '-' ? 'S' : 's') : 0;
    S_ISGID & current->buffer->st_mode ? (chmod[6] = chmod[6] == '-' ? 'S' : 's') : 0;
    S_ISVTX & current->buffer->st_mode ? (chmod[9] = chmod[9] == '-' ? 'T' : 't') : 0;
    mx_printstr(chmod);
    mx_printnchar(' ', space_num);
}
