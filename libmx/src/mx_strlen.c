int mx_strlen(const char *s) {
    int q = 0;

    for(; s[q] != '\0'; q++);
    return q;
}
