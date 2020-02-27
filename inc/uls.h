#ifndef ULS_H
#define ULS_H

#include "libmx/inc/libmx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/acl.h>

#define ANSI_COLOR_RED         "\x1b[31m"
#define ANSI_COLOR_GREEN       "\x1b[32m"
#define ANSI_COLOR_YELLOW      "\x1b[33m"
#define ANSI_COLOR_BLUE        "\x1b[34m"
#define ANSI_COLOR_MAGENTA     "\x1b[35m"
#define ANSI_COLOR_ULTRA_BLUE  "\x1b[36m"
#define ANSI_COLOR_BLCK_ON_GRN "\x1b[30;42m"
#define ANSI_COLOR_BLUE_ON_YLW "\x1b[34;43m"
#define ANSI_COLOR_BLUE_ON_BLU "\x1b[34;46m"
#define ANSI_COLOR_RESET       "\x1b[0m"

#define MX_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#define MX_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#define MX_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#define MX_ISCHR(m) (((m) & S_IFMT) == S_IFCHR)
#define MX_ISBLK(m) (((m) & S_IFMT) == S_IFBLK)
#define MX_ISFIFO(m) (((m) & S_IFMT) == S_IFIFO)
#define MX_ISSOCK(m) (((m) & S_IFMT) == S_IFSOCK)
#define MX_ISWHT(m) (((m) & S_IFMT) == S_IFWHT)
#define MX_ISEXEC(m) ((m) & S_IXUSR)
#define MX_ISBIN(m) ((m) & S_IXOTH)
#define MX_ISWRT(m) (((m) & S_IWOTH) && ((m) & S_ISVTX))

#define MX_MAJOR(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define MX_MINOR(x) ((int32_t)((x)&0xffffff))

#define MX_MAX(a, b) b &((a - b) >> 31) | a &(~(a - b) >> 31)

typedef struct stat t_stat;
typedef struct group t_group;
typedef struct dirent t_dirent;
typedef struct passwd t_passwd;
typedef struct s_flags t_flags;
typedef struct s_data t_data;
typedef struct s_d_list t_d_list;

typedef struct s_flags {
    int f_a;
    int f_A;
    int f_l;
    int f_1;
    int f_G;
    int f_C;
    int f_r;
    int f_t;
    int f_u;
    int f_c;
    int f_S;
    int f_T;
    int f_R;
    int f_f;
    int illegal;
}              t_flags;

typedef struct s_data {
    char *name;
    char *d_path;
    struct stat *buffer;
    struct s_data *next;
}              t_data;

typedef struct s_d_list {
    struct s_data *path;
    struct s_data *link;
    struct s_d_list *next_list;
}              t_d_list;

void mx_printnchar(char c, int n);
int mx_intlength(int n);
int mx_long_length(long long int n);
char *mx_lltoa(long long int number);
int mx_number_of_dir(char **arr);
int mx_number_of_flags(char **arr);
char **mx_dir_arr(int argc, char **arr);
char **mx_flags_arr(int argc, char **arr);
t_flags *mx_create_flags_struct(char ***arr_str);
bool mx_legal_flag(char ***arr_str);
void mx_print_illegal(char ***arr_str);
bool mx_find_flag(char ***arr_str, char f_char);
int mx_check_arr_dir(char ***arr_dirname);
void mx_check_flags_conflict(t_flags **flags);
bool mx_legal_dirname(const char *name);
void mx_print_wrong_dir(char ***arr_del);
void mx_sort_arrstr(int flag_r, char ***arr_str);
bool mx_status(struct stat buf);
t_data *mx_create_data(char *path, char *filename);
struct stat *mx_fill_buffer(const char *filename);
void mx_push_data_back(t_data **list, t_data *last);
t_d_list *mx_create_list(t_data *pathname, t_data *data);
void mx_push_list_back(t_d_list **list, t_d_list *last);
void mx_push_list_front(t_d_list **list, t_d_list *first);
t_d_list *mx_list_full_assembly(t_flags **flags, char ***names);
void mx_for_dir_to_list(t_flags **flags, t_d_list **list);
void mx_sort_lists_list(t_flags **flags, t_d_list **list);
void mx_l_ascii_sort(t_d_list **list);
void mx_l_sort_size(t_d_list **list);
void mx_l_sort_a_time(t_d_list **list);
void mx_l_sort_c_time(t_d_list **list);
void mx_l_sort_m_time(t_d_list **list);
void mx_l_reverse(t_d_list **list);
void mx_open_dir(t_flags **flags, t_d_list **list);
void mx_plus_insight_dir(t_d_list **list);
void mx_swap_data(t_data *first, t_data *second);
void mx_swap_list(t_d_list *first, t_d_list *second);
char *mx_make_pathname(const char *begin, const char *end);
void mx_sort_datas_list(t_flags **flags, t_d_list **list);
void mx_ascii_sort(t_data **data_list);
void mx_sort_size(t_data **data_list);
void mx_sort_a_time(t_data **data_list);
void mx_sort_c_time(t_data **data_list);
void mx_sort_m_time(t_data **data_list);
void mx_reverse_all(t_data **data_list);
int mx_size_data_list(t_data **data_list);
void mx_tbl_output(t_d_list *list, int flg_G, int flg_T);
void mx_print_total_nblocks(t_data *list);
void mx_print_permission(t_data *cur_list);
void mx_print_time(time_t *t);
bool mx_check_permission(t_d_list *list);
void mx_print_permission_denied(t_d_list *list);
void mx_check_unprintable(char **name);
void mx_print_chmod(t_data *current, int space_num, char *path);
void mx_check_unprintable(char **name);
void mx_one_column_output(t_d_list *list, int flg_G, int input);
int mx_list_of_lists_size(t_d_list **list);
void mx_all_print(t_flags **flgs, t_d_list **list, int terminal, int quant);
void mx_print_color(t_data *node);
void mx_print_minor(t_data *current, int nspaces);
void mx_print_major(t_data *current, int nspaces);
void mx_print_nlinks(t_data *current, int nspaces);
int *mx_get_row_size(t_data *current);
void mx_print_size(t_data *current, int nspaces);
void mx_print_uid(t_data *current, int nspaces);
void mx_print_gid(t_data *current, int nspaces);
void mx_out_mjmn(t_data *current, int *size);
void mx_multicolumn_output(t_d_list *list, int flg_G, int input, int window);
int mx_columns(int max_name, int list_size, int n_isatty);
int mx_max_name(t_data *list, int flg_G);
void mx_print_name(t_data *data, int flg_G);
void mx_print_spaces(const char *str, int max, int flg_G);

#endif
