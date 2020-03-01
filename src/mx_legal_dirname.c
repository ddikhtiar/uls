#include "uls.h"

bool mx_legal_dirname(const char *name) {
    struct stat buf;
    int st = stat(name, &buf);

    if (st != 0) {
        return false;
    }
    else {
        if (mx_status(buf))
            return true;
        else
            return false;
    }
}
