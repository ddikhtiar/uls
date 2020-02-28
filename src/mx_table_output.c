#include "uls.h"

static void mx_out(t_data *current, int flg_T, int flg_G, int *size);
static void print_full_date(char *str_date);
static void sx_time_out(t_data *current, int flg_T);

void mx_tbl_output(t_d_list *list, int flg_G, int flg_T) {
	t_d_list *ptr = list;
	t_data *current = ptr->link;
    int *size;
    int count = 0;
    int list_sz = mx_list_of_lists_size(&ptr);
    
    while(ptr){
        current = ptr->link;
    	if(!current) return;
        if(list_sz > 1) {
            mx_printstr(ptr->path->name);
            mx_printstr(":\n");
        }
        size = mx_get_row_size(current);
	    mx_print_total_nblocks(current);
        mx_out(current, flg_T, flg_G, size);
        (list_sz > 1 && count < list_sz - 1) ? mx_printstr("\n") : (void) (0);
        count++;
        ptr = ptr->next_list;
        free(size);
    }
}

static void mx_out(t_data *current, int flg_T, int flg_G, int *size) {
    while(current) {
        mx_print_chmod(current, 1, current->d_path);
        mx_print_nlinks(current, size[0]);
        mx_print_uid(current, size[1]);
        mx_print_gid(current, size[2]);
        mx_out_mjmn(current, size);
        sx_time_out(current, flg_T);
        if (flg_G == 1)
            mx_print_color(current);
        else
            mx_printstr(current->name);
        MX_ISLNK(current->buffer->st_mode) ? mx_print_link(current) : (void)0;
        mx_printstr("\n");
        current = current->next;
    }
}

// major and minor or not
void mx_out_mjmn(t_data *current, int *size) {
    if (MX_ISCHR(current->buffer->st_mode) ||
        MX_ISBLK(current->buffer->st_mode)) {
        mx_print_major(current, 3);
        mx_print_minor(current, 3);
    } else {
        mx_print_size(current, size[3]);
    }
}

// print time in sec and miliseconds
static void sx_time_out(t_data *current, int flg_T) {
    time_t *t;
    char *f_time;

    if(flg_T) {
        f_time = ctime(&(current->buffer->st_mtimespec.tv_sec));
        print_full_date(f_time);
    } else {
        t = &(current->buffer->st_mtimespec.tv_sec);
        mx_print_time(t);
    }
}

// print date in miliseconds
static void print_full_date(char *str_date) {
    char *date = NULL;
    str_date += 4;
    date = mx_strndup(str_date, mx_strlen(str_date) - 1);
    mx_printstr(date);
    mx_printstr(" ");
    mx_strdel(&date);
}
