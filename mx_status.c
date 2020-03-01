#include "uls.h"

bool mx_status(struct stat buf) {
    if (MX_ISREG(buf.st_mode))
        return true;
    else if (MX_ISDIR(buf.st_mode))
        return true;
    else if (MX_ISLNK(buf.st_mode))
        return true;
    else if (MX_ISCHR(buf.st_mode))
        return true;
    else if (MX_ISBLK(buf.st_mode))
        return true;
    else if (MX_ISFIFO(buf.st_mode))
        return true;
    else if (MX_ISSOCK(buf.st_mode))
        return true;
    else
        return false;
}
