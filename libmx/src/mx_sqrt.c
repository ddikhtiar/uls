int mx_sqrt(int x) {
    for (int i = 1; i <= 46340; i++) {
        if (i * i == x)
        return i;
    }
    return 0;
}
