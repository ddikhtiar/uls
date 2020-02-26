#include "uls.h"

static void sx_print_files(t_data *list, int flg_G);
static int sx_max_name(t_data *list, int flg_G);
static int sx_list_size(t_data *list);
static int sx_columns(int max_name, int list_size, int *ptr);
static int sx_col(unsigned int x, unsigned int size);
static void sx_print_name(t_data *data, int flg_G);
static void sx_print_spaces(const char *str, int max);

void mx_multicolumn_output(t_d_list *list, int flg_G, int input) {
    int size = mx_list_of_lists_size(&list);

    while (list) {
        if (size > 1 && list->path != NULL) {
            if (input != 1) {
                mx_printstr(list->path->name);
                mx_printstr(":\n");
            }
            else
                input = 0;
        }
        if (!mx_check_permission(list))
            mx_print_permission_denied(list);
        else {
            if (list->link != NULL)
                sx_print_files(list->link, flg_G);
        }
        list = list->next_list;
        if (list)
            mx_printchar('\n');
    }
}

static void sx_print_files(t_data *list, int flg_G) {
    t_data *ptr = list;
    t_data *ptr1 = NULL;
    int max = sx_max_name(list, flg_G);
    int list_size = sx_list_size(list);
    int window = 0;
    int columns = sx_columns(max, list_size, &window);
    int str = list_size / columns;
    int count;
    int over;

    if (list_size % columns != 0)
        str++;
    count = str;
    while (str) {
        ptr = list;
        over = 1;
        while (ptr) {
            ptr1 = ptr;
            sx_print_name(ptr1, flg_G);
            for (int i = 1; i <= count; i++) {
                ptr = ptr->next;
                if (ptr == NULL)
                    break;
            }
            over++;
            if (!ptr || over > (window / max)) {
                mx_printchar('\n');
                break;
            }
            else {
                sx_print_spaces(ptr1->name, max);
            }
        }
        list = list->next;
        str--;
    }
}

static int sx_max_name(t_data *list, int flg_G) {
    int current = 0;
    int max = 0;

    while (list) {
        current = mx_strlen(list->name);
        if (current > max)
            max = current;
        list = list->next;
    }
    if (flg_G == 1)
        max += 1;
    else
        max += (8 - (max % 8));
    return max;
}

static int sx_list_size(t_data *list) {
    int size = 0;

    while (list) {
        size++;
        list = list->next;
    }
    return size;
}

static int sx_columns(int max_name, int list_size, int *ptr) {
    struct winsize sz;
    int window = 0;
    int column = 1;
    int x = 0;

    ioctl(0, TIOCGWINSZ, &sz);
    window = sz.ws_col;
    *ptr = window;
    x = window/max_name;
    if (x > 1) {
        if (x >= list_size)
            column = list_size;
        else
            column = sx_col(x, list_size);
    }
    return column;
}

static int sx_col(unsigned int x, unsigned int size) {
    int y = 0;

    while (x > 1) {
        y = size / x;
        if (y >= 2) {
            if (x > 2 && size % (x - 1) == 0)
                return (x - 1);
            else
                return x;
        }
        else
            x--;
    }
    return x;
}

static void sx_print_name(t_data *data, int flg_G) {
    if (flg_G == 1)
        mx_print_color(data);
    else
        mx_printstr(data->name);
}

static void sx_print_spaces(const char *str, int max) {
    int len = mx_strlen(str);
    int spaces = max - len;

    for (; spaces > 0; spaces--)
        mx_printchar(' ');
}
