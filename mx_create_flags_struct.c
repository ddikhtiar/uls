#include "uls.h"

static void sx_push_null(t_flags **fff) {
    t_flags *flags = *fff;

    flags->f_a = 0;
    flags->f_A = 0;
    flags->f_l = 0;
    flags->f_1 = 0;
    flags->f_G = 0;
    flags->f_C = 0;
    flags->f_r = 0;
    flags->f_t = 0;
    flags->f_u = 0;
    flags->f_c = 0;
    flags->f_S = 0;
    flags->f_T = 0;
    flags->f_R = 0;
    flags->f_f = 0;
    flags->illegal = 0;
}

static void sx_modify_end_end(t_flags **flags, char ***arr_str) {
    if (mx_find_flag(arr_str, 'l')) {
        (*flags)->f_l = 1;
        (*flags)->f_1 = 0;
        (*flags)->f_C = 0;
    }
    if (mx_find_flag(arr_str, '1')) {
        (*flags)->f_1 = 1;
        (*flags)->f_C = 0;
        (*flags)->f_l = 0;
    }
    if (mx_find_flag(arr_str, 'C')) {
        (*flags)->f_C = 1;
        (*flags)->f_1 = 0;
        (*flags)->f_l = 0;
    }
}

static void sx_modify_end(t_flags **flags, char ***arr_str) {
    if (mx_find_flag(arr_str, 'a'))
        (*flags)->f_a = 1;
    if (mx_find_flag(arr_str, 'A'))
        (*flags)->f_A = 1;
    if (mx_find_flag(arr_str, 'G'))
        (*flags)->f_G = 1;
    if (mx_find_flag(arr_str, 'r'))
        (*flags)->f_r = 1;
    if (mx_find_flag(arr_str, 't'))
        (*flags)->f_t = 1;
    if (mx_find_flag(arr_str, 'S'))
        (*flags)->f_S = 1;
    if (mx_find_flag(arr_str, 'T'))
        (*flags)->f_T = 1;
    if (mx_find_flag(arr_str, 'R'))
        (*flags)->f_R = 1;
    if (mx_find_flag(arr_str, 'f'))
        (*flags)->f_f = 1;
    sx_modify_end_end(flags, arr_str);
}

static void sx_modify(t_flags **flags, char ***arr_str) {
    if (*arr_str == NULL)
        return;
    if (!mx_legal_flag(arr_str)) {
        (*flags)->illegal = 1;
        mx_print_illegal(arr_str);
    }
    else {
        if (mx_find_flag(arr_str, 'u')) {
            (*flags)->f_u = 1;
            (*flags)->f_c = 0;
        }
        if (mx_find_flag(arr_str, 'c')) {
            (*flags)->f_c = 1;
            (*flags)->f_u = 0;
        }
        sx_modify_end(flags, arr_str);
        mx_check_flags_conflict(flags);
    }
}

t_flags *mx_create_flags_struct(char ***arr_str) {
    t_flags *flags = (t_flags *) malloc(sizeof(t_flags));

    if (flags == NULL)
        return NULL;
    sx_push_null(&flags);
    sx_modify(&flags, arr_str);
    return flags;
}
