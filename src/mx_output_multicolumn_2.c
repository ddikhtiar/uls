#include "uls.h"

int mx_count_rows(int elem_count, int col_num) {
	int row_num = 0;

	row_num = elem_count / col_num;
	if((elem_count % col_num) > 0) {
		row_num++;
	}
	return row_num;
}
