#include "libmx.h"

bool mx_isalpha(char c) {
    if (c >= 65 && c <= 90)
        return true;
    else if (c >= 97 && c <= 122)
        return true;
    else
        return false;
}
