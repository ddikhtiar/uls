char *mx_strncpy(char *dst, const char *src, int len) {
    char *ch = dst;

    while (len > 0 && *src != '\0') {
        *ch++ = *src++;
        --len;
    }
    while (len > 0) {
        *ch++ = '\0';
        --len;
    }
    return dst;
}
