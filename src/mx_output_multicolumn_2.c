#include "uls.h"

static void sx_print_tabs(int col_len, int current_len);

int mx_count_rows(int elem_count, int col_num) {
	int row_num = 0;

	row_num = elem_count / col_num;
	if((elem_count % col_num) > 0) {
		row_num++;
	}
	return row_num;
}

void mx_print_col(t_data *current, int i, int row_num,
				  int elem_count, int col_len) {
	int k = 0;
	int j = i;

	while (k < i) {
		k++;
		current = current->next;
	}
	for(j = i; j < elem_count; j += row_num) {
		mx_printstr(current->name);
		sx_print_tabs(col_len, mx_strlen(current->name));
		k = 0;
		while (current && k < row_num) {
			k++;
			current = current->next;
		}
	}
	mx_printstr("\n");
}

//count and print number of tabs needed to add for every string
static void sx_print_tabs(int col_len, int current_len) {
	int tabs_count = 0;

	tabs_count = (col_len - current_len) / 8;
	if(!(current_len % 8)) {
		--tabs_count;
	}
	while (tabs_count--) {
        mx_printchar('\t');
	}
    mx_printchar('\t');
}
