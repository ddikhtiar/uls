#include "libmx.h"

static void split(const char *str, char **arr, int words, char CH);

char **mx_strsplit(const char *s, char c) {
    int k;
    char **arr = NULL;

    if (s == NULL)
        return NULL;
    k = mx_count_words(s, c);
    arr = (char **) malloc(sizeof(char *) * (k + 1));
    split(s, arr, k, c);
    return arr;
}

static void split(const char *str, char **array, int words, char CH) {
    for (int i = 0; i < words; i++) {
        int len_word = 0;
        char *count = (char *)str;

        while (len_word == 0 && *count != '\0') {
            count = (char *)str;
            if (*count != CH) {
                for (; *(count + len_word) != CH
                    && *(count + len_word) != '\0'; len_word++);
            }
            else
                str++;
        }
        array[i] = mx_strnew(len_word);
        array[i] = mx_strncpy(array[i], str, len_word);
        str += len_word;
    }
    array[words] = NULL;
}
