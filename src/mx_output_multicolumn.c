#include "uls.h"

static int sx_count_max_str(t_data *cur_list, int *elem_num);
static int sx_count_col_len(int max_str);
static int sx_count_col_num(int col_len);

void mx_mc_output(t_d_list *list){
	t_d_list *ptr = list;
	t_data *current = NULL;
	int col_len = 0;
	int max_str = 0;
	int col_num = 0;
	int elem_count = 0;
	int	row_num = 0;
	int i = 0;

	if (!ptr){
        return;
	}
	while(ptr){
		current = ptr->link;
		printf("%s:\n", ptr->path->name);
		// elem_count = 0;
		max_str = sx_count_max_str(current, &elem_count);
		col_len = sx_count_col_len(max_str);
		col_num = sx_count_col_num(col_len);
		row_num = mx_count_rows(elem_count, col_num);
		// printf("elem_count = %d max_str = %d col_len = %d col_num = %d row_num = %d\n", elem_count, max_str, col_len, col_num, row_num);
		// mx_printstr(ptr->path->name);
		// mx_printstr("\n");
		for(i = 0; i < row_num; i++) {
			// current = ptr->link;
			mx_print_col(current, i, row_num, elem_count, col_len);
		}
		// printf("------- AAAAAA -----\n");
		ptr = ptr->next_list;
		mx_printstr("\n");
	}
}

// count max length string
static int sx_count_max_str(t_data *cur_list, int *elem_num) {
	*elem_num = 0;
	// t_d_list *ptr = list;
	// t_data *current = NULL;
	int max_str = 0;

	// while(ptr){
		// current = ptr->link;
		while(cur_list) {
			if(mx_strlen(cur_list->name) > max_str) {
				max_str = mx_strlen(cur_list->name);
			}
			cur_list = cur_list->next;
			*elem_num = *elem_num + 1;
		}
		// ptr = ptr->next_list;
	// }
	// printf("%d\n", max_str);
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
