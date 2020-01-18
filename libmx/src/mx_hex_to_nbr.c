unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    unsigned long temp = 0;
    int size;

    for (size = 0; hex[size] != '\0'; size++);
    for (int i = 1; i <= size; i++) {
        temp = hex[size - i];
        if (temp > 47 && temp < 58)
            temp -= 48;
        else if (temp > 64 && temp < 71)
            temp -= 55;
        else if (temp > 96 && temp < 103)
            temp -= 87;
        else
            return 0;
        for (int j = i - 1; j > 0; j--)
            temp = temp * 16;
        result = result + temp;
    }
    return result;
}
