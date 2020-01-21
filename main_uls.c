#include "uls.h"

inr main (int argc, char **argv) {
	if (argc == 1)
		mx_bacic_out();
	else
		mx_flags_out(argv);
	exit(0);
}
