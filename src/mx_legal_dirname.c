#include "uls.h"

bool mx_legal_dirname(const char *name) {
    struct stat buf;
	int st = stat(name, &buf);

	if (st != 0) {
		mx_printstr("NOT FILE OR DIR\n");
		return false;
	}
	else {
		if (mx_status(buf))
			return true;
		else
			return false;
	}
}
