#include "uls.h"

void mx_tbl_output(t_d_list *list) {
	t_d_list *ptr = list;
	t_data *current = NULL;
	current = ptr->link;
	t_passwd *passwd = getpwuid(current->buffer->st_uid);
	t_group *group = getgrgid(current->buffer->st_gid);
	
	mx_print_total_nblocks(current);
	while(current) {
    	mx_printstr("\n");
    	mx_print_permission(current);
	    mx_printstr(" ");
    	mx_printint(current->buffer->st_nlink);
	    mx_printstr(" ");
    	mx_printstr(passwd->pw_name);
    	mx_printstr(" ");
    	mx_printstr(group->gr_name);
	    mx_printstr(" ");
		mx_printint(current->buffer->st_size);
		mx_printstr(" bytes ");
	    mx_printstr(current->name);
	    mx_printstr("\n");
		current = current->next;
	}
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
