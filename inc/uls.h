#ifndef ULS_H
#define ULS_H

#include "libmx/inc/libmx.h"
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
#define MX_ISREG(m) (((m) & 0170000) == 0100000)
#define MX_ISDIR(m) (((m) & 0170000) == 0040000)
#define MX_ISLNK(m) (((m) & 0170000) == 0120000)
#define MX_ISCHR(m) (((m) & 0170000) == 0020000)
#define MX_ISBLK(m) (((m) & 0170000) == 0060000)
#define MX_ISFIFO(m) (((m) & 0170000) == 0010000)
#define MX_ISSOCK(m) (((m) & 0170000) == 0140000)
*/

typedef struct s_flags {
    int f_a; //Включает в список файлы и папки, начинающиеся с '.'
    int f_A; //Аналогичен f_a, но игнорирует "." и ".."
    int f_l; //Подробный вывод данных
    int f_1; //Выводит список в одну колонну
    int f_G; //Изменяет цвета файлов в зависимости от типа
    int f_C; //Выводит список в несколько колонн
    int f_r; //Выводит в обратном алфавитном порядке
    int f_t; //Сортирует по времени последней модификации файла
             //до сортировки по алфавиту
    int f_u; //Использует время последнего открытия файла вместо 
             //времени изменения для сортировки вместе с f_t или f_l
    int f_c; //Использует для сортировки время последнего изменения файла
             //работает вместе с f_t или f_l
    int f_S; //Сортирует файлы по размеру
    int f_T; //Показывает полное время изменения файла от года до секунд
    int f_R; //Рекурсивный вывод всех файлов и папок с вложенными файлами
    int illegal;
} t_flags;

typedef struct s_data {
    char *name;
    struct stat *buffer;
    struct s_data *next;
} t_data;

typedef struct s_d_list {
    struct s_data *link;
    struct s_d_list *next_list;
} t_d_list;

int mx_number_of_dir(char **arr); //Возвращает кол-во дирректорий
int mx_number_of_flags(char **arr); //Возвращает кол-во флагов
char **mx_dir_arr(int argc, char **arr); //Возвращает массив названий дир-рий
char **mx_flags_arr(int argc, char **arr); //Возвращает массив флагов
//void mx_flags_out(char **arr);
//char **mx_arr_filenames(const char *dir_name); //Возвращает массив названий
                                               //файлов из заданной папки
t_flags *mx_create_flags_struct(char ***arr_str); //Создает структуру флагов
bool mx_legal_flag(char ***arr_str); //Проверяет флаги на валидность
void mx_print_illegal(char ***arr_str); //Выводит ошибку, если найден
                                        //не валидный флаг
bool mx_find_flag(char ***arr_str, char f_char); //Проверяет наличие флага
                                                 //во входящем массиве
void mx_check_arr_dir(char ***arr_dirname); //Проверяет входящий массив папок,
                                            //удаляет не валидные названия
                                            //и выводит ошибку "No such..."
bool mx_legal_dirname(const char *name); //Проверяет, является ли указанная
                                         //строка именем файла/папки/ссылкой
void mx_print_wrong_dir(const char *name); //Выводит ошибку, если указано
                                           //неверное имя файла/папки
bool mx_status(struct stat buf); //Часть mx_legal_dirname()
t_data *mx_create_data(const char *filename); //Создает лист с данными о файле
struct stat *mx_fill_buffer(const char *filename); //Заполняет буффер
                                                   //в листе данными из stat
void mx_push_data_back(t_data **list, const char *filename); //Добавляет лист
                                                             //с данными файла
                                                             //в конец списка
t_d_list *mx_create_list(t_data *data); //Создает лист со списком данных
void mx_push_list_back(t_d_list **first, t_d_list *list) //Добавляет список
                                                         //данных в конец
                                                         //списка списков
//t_node *mx_create_node(t_data *current);
//t_node *mx_get_filenames(const char *dir_name);

#endif
