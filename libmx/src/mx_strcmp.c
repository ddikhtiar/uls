int mx_strcmp(const char *s1, const char *s2) {
    for (int i = 0; ; ) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
        else if (s1[i] == s2[i])
            i++;
        else
            return s1[i] - s2[i];
    }
}
