#include "uls.h"

static int sx_count_max_str(t_data *cur_list, int *elem_num);
static int sx_count_col_len(int max_str);
static int sx_count_col_num(int col_len);
static void sx_print_col_2(t_data *current, int elem_count);

void mx_mc_output(t_d_list *list){
	t_d_list *ptr = list;
	t_data *current = NULL;
	int elem_count = 0;
	// int counter = 0;

	while(ptr){
		current = ptr->link;
		mx_printstr(ptr->path->name);
		mx_printstr(":\n");
		if (!mx_check_permission(ptr))
            mx_print_permission_denied(ptr);
		else {
			sx_print_col_2(current, elem_count);
		}
		ptr = ptr->next_list;
		if (ptr != NULL)
			mx_printstr("\n");
	}
}

static void sx_print_col_2(t_data *current, int elem_count) {
	int col_len = 0;
	int max_str = 0;
	int col_num = 0;
	int	row_num = 0;
	int i = 0;

	max_str = sx_count_max_str(current, &elem_count);
	col_len = sx_count_col_len(max_str);
	col_num = sx_count_col_num(col_len);
	row_num = mx_count_rows(elem_count, col_num);
	for(i = 0; i < row_num; i++) {
		mx_print_col(current, i, row_num, elem_count, col_len);
	}
}

// count max length string
static int sx_count_max_str(t_data *cur_list, int *elem_num) {
	*elem_num = 0;
	int max_str = 0;

	while(cur_list) {
		if(mx_strlen(cur_list->name) > max_str) {
			max_str = mx_strlen(cur_list->name);
		}
		cur_list = cur_list->next;
		*elem_num = *elem_num + 1;
	}
	return max_str;
}

// count number of symbols in column
static int sx_count_col_len(int max_str) {
	int col_len = max_str;
	
	if(!(col_len % 8)) {
		col_len += 8;
		return col_len;
	}
	while((col_len % 8) > 0){
		col_len++;
	}
	return col_len;
}

// count nomber of columns depend on term width
static int sx_count_col_num(int col_len) {
	struct winsize sz;
	int w_sz_col = 0;
	int col_num = 0;

	// getting width of terminal
    ioctl(0, TIOCGWINSZ, &sz);
    w_sz_col = sz.ws_col;
    col_num = w_sz_col/col_len;
    return col_num;
}
