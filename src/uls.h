#ifndef ULS_H
#define ULS_H

#include "../libmx/inc/libmx.h"
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

int mx_number_of_dir(char **arr); //Возвращает кол-во дирректорий
int mx_number_of_flags(char **arr); //Возвращает кол-во флагов
char **mx_dir_arr(char **arr); //Возвращает массив названий дирректорий
char **mx_flags_arr(char **arr); //Возвращает массив флагов
void mx_flags_out(char **arr);
char **mx_arr_filenames(const char *dir_name); //Возвращает массив названий
                                               //файлов из заданной папки

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

t_flags *mx_create_flags_struct(char ***arr_str);
bool mx_legal_flag(char ***arr_str);
void mx_print_illegal(char ***arr_str);
bool mx_find_flag(char ***arr_str, char f_char);

#endif
