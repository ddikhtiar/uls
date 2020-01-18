#include "libmx.h"

bool mx_isspace(char c) {
    if (c == '\f' || c == '\n' || c == '\r'
        || c == '\t' || c == '\v' || c == ' ')
        return true;
    else
        return false;
}
