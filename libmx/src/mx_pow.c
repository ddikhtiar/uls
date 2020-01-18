double mx_pow(double n, unsigned int pow) {
    double result = 1;

    for (unsigned int i = 1; i <= pow; i++)
        result = result * n;
    if (pow == 0)
        return 1;
    else
        return result;
}
