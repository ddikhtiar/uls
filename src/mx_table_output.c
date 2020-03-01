#include "uls.h"

// print date in miliseconds
static void print_full_date(char *str_date) {
    char *date = NULL;
    str_date += 4;
    date = mx_strndup(str_date, mx_strlen(str_date) - 1);
    mx_printstr(date);
    mx_printstr(" ");
    mx_strdel(&date);
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

static void sx_total(t_d_list *list, int flg_T, int flg_G) {
    t_data *cur = NULL;
    int *size;

    cur = ((list->path && MX_ISLNK(list->path->buffer->st_mode)
            && mx_check_slash(list->path->name)) ? list->path : list->link);
    size = mx_get_row_size(cur);
    mx_out(cur, flg_T, flg_G, size);
    free(size);
}

void mx_tbl_output(t_d_list *list, int flg_G, int flg_T, int input) {
    int list_sz = mx_list_of_lists_size(&list);

    while(list){
        if (list_sz > 1 && list->path != NULL) {
            if (input != 1) {
                mx_printstr(list->path->name);
                mx_printstr(":\n");
                (list->link != NULL) ? mx_print_nblocks(list->link) : (void)0;
            }
            else
                input = 0;
        }
        if (!mx_check_permission(list))
            mx_print_permission_denied(list);
        else if (list->link != NULL)
            sx_total(list, flg_T, flg_G);
        list = list->next_list;
        if (list)
            mx_printchar('\n');
    }
}
