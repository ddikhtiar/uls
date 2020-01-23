#include "uls.h"

void mx_print_wrong_dir(const char *name) {
	mx_printerr("uls: ");
	mx_printerr(name);
	mx_printerr(": No such file or directory\n");
}
