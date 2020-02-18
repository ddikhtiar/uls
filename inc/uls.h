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

#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_BOLD_GREEN "\x1b[32;1m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_BOLD_CYAN  "\x1b[96;1m"
#define ANSI_COLOR_RESET      "\x1b[0m"

#define MX_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#define MX_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#define MX_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#define MX_ISCHR(m) (((m) & S_IFMT) == S_IFCHR)
#define MX_ISBLK(m) (((m) & S_IFMT) == S_IFBLK)
#define MX_ISFIFO(m) (((m) & S_IFMT) == S_IFIFO)
#define MX_ISSOCK(m) (((m) & S_IFMT) == S_IFSOCK)

/*
 * #define MX_ISREG(m) (((m) & 0170000) == 0100000)
 * #define MX_ISDIR(m) (((m) & 0170000) == 0040000)
 * #define MX_ISLNK(m) (((m) & 0170000) == 0120000)
 * #define MX_ISCHR(m) (((m) & 0170000) == 0020000)
 * #define MX_ISBLK(m) (((m) & 0170000) == 0060000)
 * #define MX_ISFIFO(m) (((m) & 0170000) == 0010000)
 * #define MX_ISSOCK(m) (((m) & 0170000) == 0140000)
 */

typedef struct group t_group;
typedef struct dirent t_dirent;
typedef struct passwd t_passwd;
typedef struct s_flags t_flags;
typedef struct s_data t_data;
typedef struct s_d_list t_d_list;

typedef struct s_flags {
    int f_a;     //Включает в список файлы и папки, начинающиеся с '.'
    int f_A;     //Аналогичен f_a, но игнорирует "." и ".."
    int f_l;     //Подробный вывод данных - 
    int f_1;     //Выводит список в одну колонну -
    int f_G;     //Изменяет цвета файлов в зависимости от типа -
    int f_C;     //Выводит список в несколько колонн
    int f_r;     //Выводит в обратном порядке
    int f_t;     //Сортирует по времени последней модификации файла -
                 //до сортировки по алфавиту
    int f_u;     //Использует время последнего открытия файла вместо 
                 //времени изменения для сортировки вместе с f_t или f_l
    int f_c;     //Использует для сортировки время последнего изменения файла
                 //работает вместе с f_t или f_l
    int f_S;     //Сортирует файлы по размеру
    int f_T;     //Показывает полное время изменения файла от года до секунд
    int f_R;     //Рекурсивный вывод всех файлов и папок с вложенными файлами
    int f_f;     //Отключает любые сортировки и включает -a
    int illegal; //Присутствует не ликвидный флаг/прекращает работу программы
} t_flags;

typedef struct s_data {
    char *name;          //Имя файла
    struct stat *buffer; //Данные stat'a
    struct s_data *next; //Ссылка на следующий лист
    uid_t st_uid;        //User ID of owner */
    gid_t st_gid;        //Group ID of owner */
    dev_t st_rdev;       //Device ID (if special file) */
    off_t st_size;       //Total size, in bytes */
} t_data;

typedef struct s_d_list {
    struct s_data *path;        //Имя папки с данными о ней (1 лист)
    struct s_data *link;        //Список с данными файлов
    struct s_d_list *next_list; //Ссылка на следующий лист со списком данных
} t_d_list;

int mx_number_of_dir(char **arr);              //Возвращает кол-во дирректорий
int mx_number_of_flags(char **arr);                 //Возвращает кол-во флагов
char **mx_dir_arr(int argc, char **arr);  //Возвращает массив названий дир-рий
char **mx_flags_arr(int argc, char **arr);          //Возвращает массив флагов
t_flags *mx_create_flags_struct(char ***arr_str);   //Создает структуру флагов
bool mx_legal_flag(char ***arr_str);           //Проверяет флаги на валидность
void mx_print_illegal(char ***arr_str);          //Выводит ошибку, если найден
                                                 //не валидный флаг
bool mx_find_flag(char ***arr_str, char f_char);     //Проверяет наличие флага
                                                     //во входящем массиве
int mx_check_arr_dir(char ***arr_dirname);           //Проверяет входящий --->
// ---> массив папок, удаляет не валидные названи и выводит ошибку "No such.."
void mx_check_flags_conflict(t_flags **flags);          //Совместимость флагов
bool mx_legal_dirname(const char *name);    //Проверяет, является ли указанная
                                           //строка именем файла/папки/ссылкой
void mx_print_wrong_dir(char ***arr_del);       //Выводит ошибку, если указано
                                                //неверное имя файла/папки
void mx_sort_arrstr(int flag_r, char ***arr_str);    //Сортировка по ASCII +/-
bool mx_status(struct stat buf);                    //Часть mx_legal_dirname()
t_data *mx_create_data(const char *path, const char *filename);        // --->
// ---> Создает лист с данными о файле
struct stat *mx_fill_buffer(const char *filename);          //Заполняет буффер
                                                     //в листе данными из stat
void mx_push_data_back(t_data **list, t_data *last);          //Добавляет лист
                                                             //с данными файла
                                                              //в конец списка
t_d_list *mx_create_list(t_data *pathname, t_data *data);              // --->
// ---> Создает лист со списком данных
void mx_push_list_back(t_d_list **list, t_d_list *last);               // --->
// ---> Добавляет список данных в конец списка списков
void mx_push_list_front(t_d_list **list, t_d_list *first);             // --->
// ---> Добавляет список данных в начало списка списков
t_d_list *mx_list_full_assembly(t_flags **flags, char ***names);            // --->
// ---> Создает полный список списков с данными
void mx_for_dir_to_list(t_flags **flags, t_d_list **list);             // --->
// ---> Добаляет файлы в списки соотв. папок (рекурсивная)
void mx_sort_lists_list(t_flags **flags, t_d_list **list);             // --->
// ---> В зависимости от флагов, применяет одну из сортировок ниже:
void mx_l_ascii_sort(t_d_list **list);            //Сорт. в алфавитном порядке
void mx_l_sort_size(t_d_list **list);                       //Сорт. по размеру
void mx_l_sort_a_time(t_d_list **list);       //Сорт. по времени посл. доступа
void mx_l_sort_c_time(t_d_list **list);     //Сорт. по времени посл. изменения
void mx_l_sort_m_time(t_d_list **list);   //Сорт. по времени посл. модификации
void mx_l_reverse(t_d_list **list);               //Меняет порядок на обратный
void mx_open_dir(t_flags **flags, t_d_list **list);                    // --->
// ---> Добавляет файлы из папки в соотв. ей список
void mx_plus_insight_dir(t_d_list **list);                             // --->
// ---> Добавляет в список списков новый лист папки
void mx_swap_data(t_data *first, t_data *second);                      // --->
// ---> Меняет местами листы в списке данных
void mx_swap_list(t_d_list *first, t_d_list *second);                  // --->
// ---> Меняет местами листы в списке листов
char *mx_make_pathname(const char *begin, const char *end);            // --->
// ---> Собирает путь к файлу из папки с бинарником
void mx_sort_datas_list(t_flags **flags, t_d_list **list);             // --->
// ---> В зависимости от флагов, применяет одну из сортировок ниже:
void mx_ascii_sort(t_data **data_list);           //Сорт. в алфавитном порядке
void mx_sort_size(t_data **data_list);                      //Сорт. по размеру
void mx_sort_a_time(t_data **data_list);      //Сорт. по времени посл. доступа
void mx_sort_c_time(t_data **data_list);    //Сорт. по времени посл. изменения
void mx_sort_m_time(t_data **data_list);  //Сорт. по времени посл. модификации
void mx_reverse_all(t_data **data_list);          //Меняет порядок на обратный
void mx_mc_output(t_d_list *list);                           //вивід в колонки
int mx_size_data_list(t_data **data_list); //Количество листов в списке данных
int mx_count_rows(int elem_count, int col_num); //рахує к-ть рядків для виводу
void mx_print_col(t_data *current, int i, int row_num,
                  int elem_count, int col_len); //вивід однієї дерикторії
void mx_tbl_output(t_d_list *list); // -l
void mx_print_total_nblocks(t_data *list); // рахує total blocks для -l
void mx_print_permission(t_data *cur_list); // вивід прав доступа -l

#endif
