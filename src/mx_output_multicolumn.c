#include "uls.h"

static int sx_count_max_str(t_d_list *list);
static int sx_count_col_len(int max_str);
static void sx_print_tabs(int col_len, int current_len);
static int sx_count_col_num(int col_len);

void mx_mc_output(t_d_list *list){
	t_d_list *ptr = list;
	t_data *current = NULL;
	int col_len = 0;
	int max_str = 0;
	int col_num = 0;
	int i = 0;

	max_str = sx_count_max_str(list);
	col_len = sx_count_col_len(max_str);
	col_num = sx_count_col_num(col_len);
	while(ptr){
		current = ptr->link;
		while(current) {
			mx_printstr(current->name);
			sx_print_tabs(col_len, mx_strlen(current->name));
			if(!(i % col_num)) {
				mx_printstr("\n");
			}
			i++;
			current = current->next;
		}
		ptr = ptr->next_list;
	}
	mx_printstr("\n");
}

// count max length string
static int sx_count_max_str(t_d_list *list) {
	t_d_list *ptr = list;
	t_data *current = NULL;
	int max_str = 0;

	while(ptr){
		current = ptr->link;
		while(current) {
			if(mx_strlen(current->name) > max_str) {
				max_str = mx_strlen(current->name);
			}
			current = current->next;
		}
		ptr = ptr->next_list;
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

//count and print number of tabs needed to add for every string
static void sx_print_tabs(int col_len, int current_len) {
	int tabs_count = 0;

	tabs_count = (col_len - current_len) / 8;
	if(!(current_len % 8)) {
		--tabs_count;
	}
	while (tabs_count--)
        mx_printchar('\t');
    mx_printchar('\t');
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
