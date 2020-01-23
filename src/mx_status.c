#include "uls.h"

bool mx_status(struct stat buf) {
    if (OUR_ISREG(buf.st_mode))
        return true;
    else if (OUR_ISDIR(buf.st_mode))
        return true;
    else if (OUR_ISLNK(buf.st_mode))
        return true;
    else if (OUR_ISCHR(buf.st_mode))
        return true;
    else if (OUR_ISBLK(buf.st_mode))
        return true;
    else if (OUR_ISFIFO(buf.st_mode))
        return true;
    else if (OUR_ISSOCK(buf.st_mode))
        return true;
    else
        return false;
}
