#include "uls.h"

t_node *mx_cr_node(t_data *current) {
	t_node *list = (t_node*)malloc(sizeof(t_node));
	list->cur_data = (t_data*)malloc(sizeof(t_data));
	list->next = (t_node*)malloc(sizeof(t_data));

	list->cur_data = current;
	list->next = NULL;

	return list;
}
