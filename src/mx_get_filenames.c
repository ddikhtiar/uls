#include "uls.h"

static void output_nodes(t_node *node){
	t_node *current = node;
	while(current != NULL) {
		mx_printstr(current->cur_data->file_name);
		mx_printstr("\n");
		current = current->next;
	}
}

t_node *mx_get_filenames(const char *dir_name) {
	DIR *current = opendir(dir_name);
	struct dirent *filename = NULL;
	t_node *node = NULL;
	t_node *tail = NULL;
	t_node *head = NULL;

	for (int i = 0; (filename = readdir(current)) != NULL; i++){
		node = mx_cr_node(mx_create_data(filename->d_name));
		if (tail == NULL && head == NULL){
			tail = node;
			head = node;
			continue;
		}
		tail->next = node;
		tail = node;
	}
	output_nodes(head);
	if (closedir(current) < 0)
		return NULL;
	return node;
}
