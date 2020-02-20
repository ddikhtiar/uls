APP_NAME = uls

LIBMXF = libmx

LIB_NAME = libmx.a

INC = uls.h

INCF = inc/uls.h

SRC = \
    main.c \
    mx_ascii_sort.c \
    mx_check_arr_dir.c \
    mx_check_flags_conflict.c \
    mx_check_permission.c \
    mx_check_unprintable.c \
    mx_create_data.c \
    mx_create_flags_struct.c \
    mx_create_list.c \
    mx_dir_arr.c \
    mx_fill_buffer.c \
    mx_find_flag.c \
    mx_flags_arr.c \
    mx_for_dir_to_list.c \
    mx_l_ascii_sort.c \
    mx_l_reverse.c \
    mx_l_sort_a_time.c \
    mx_l_sort_c_time.c \
    mx_l_sort_m_time.c \
    mx_l_sort_size.c \
    mx_legal_dirname.c \
    mx_legal_flag.c \
    mx_list_full_assembly.c \
    mx_list_of_lists_size.c \
    mx_make_pathname.c \
    mx_number_of_dir.c \
    mx_number_of_flags.c \
    mx_one_column_output.c \
    mx_open_dir.c \
    mx_plus_insight_dir.c \
    mx_print_illegal.c \
    mx_print_permission_denied.c \
    mx_print_wrong_dir.c \
    mx_push_data_back.c \
    mx_push_list_back.c \
    mx_push_list_front.c \
    mx_reverse_all.c \
    mx_size_data_list.c \
    mx_sort_a_time.c \
    mx_sort_arrstr.c \
    mx_sort_c_time.c \
    mx_sort_datas_list.c \
    mx_sort_lists_list.c\
    mx_sort_m_time.c \
    mx_sort_size.c \
    mx_status.c \
    mx_swap_data.c \
    mx_swap_list.c \
    mx_output_multicolumn.c \
    mx_output_multicolumn_2.c \
    mx_table_output.c \
    mx_print_total_blocks.c \
    mx_print_time.c \
    mx_printnchar.c \

SRCF = \
    src/main.c \
    src/mx_ascii_sort.c \
    src/mx_check_arr_dir.c \
    src/mx_check_flags_conflict.c \
    src/mx_check_permission.c \
    src/mx_check_unprintable.c \
    src/mx_create_data.c \
    src/mx_create_flags_struct.c \
    src/mx_create_list.c \
    src/mx_dir_arr.c \
    src/mx_fill_buffer.c \
    src/mx_find_flag.c \
    src/mx_flags_arr.c \
    src/mx_for_dir_to_list.c \
    src/mx_l_ascii_sort.c \
    src/mx_l_reverse.c \
    src/mx_l_sort_a_time.c \
    src/mx_l_sort_c_time.c \
    src/mx_l_sort_m_time.c \
    src/mx_l_sort_size.c \
    src/mx_legal_dirname.c \
    src/mx_legal_flag.c \
    src/mx_list_full_assembly.c \
    src/mx_list_of_lists_size.c \
    src/mx_make_pathname.c \
    src/mx_number_of_dir.c \
    src/mx_number_of_flags.c \
    src/mx_one_column_output.c \
    src/mx_open_dir.c \
    src/mx_plus_insight_dir.c \
    src/mx_print_illegal.c \
    src/mx_print_permission_denied.c \
    src/mx_print_wrong_dir.c \
    src/mx_push_data_back.c \
    src/mx_push_list_back.c \
    src/mx_push_list_front.c \
    src/mx_reverse_all.c \
    src/mx_size_data_list.c \
    src/mx_sort_a_time.c \
    src/mx_sort_arrstr.c \
    src/mx_sort_c_time.c \
    src/mx_sort_datas_list.c \
    src/mx_sort_lists_list.c \
    src/mx_sort_m_time.c \
    src/mx_sort_size.c \
    src/mx_status.c \
    src/mx_swap_data.c \
    src/mx_swap_list.c \
    src/mx_output_multicolumn.c \
    src/mx_output_multicolumn_2.c \
    src/mx_table_output.c \
    src/mx_print_total_blocks.c \
    src/mx_print_time.c \
    src/mx_printnchar.c \

OBJ = $(SRC:.c=.o)

OBJO = \
    obj/main.o \
    obj/mx_ascii_sort.o \
    obj/mx_check_arr_dir.o \
    obj/mx_check_flags_conflict.o \
    obj/mx_check_permission.o \
    obj/mx_check_unprintable.o \
    obj/mx_create_data.o \
    obj/mx_create_flags_struct.o \
    obj/mx_create_list.o \
    obj/mx_dir_arr.o \
    obj/mx_fill_buffer.o \
    obj/mx_find_flag.o \
    obj/mx_flags_arr.o \
    obj/mx_for_dir_to_list.o \
    obj/mx_l_ascii_sort.o \
    obj/mx_l_reverse.o \
    obj/mx_l_sort_a_time.o \
    obj/mx_l_sort_c_time.o \
    obj/mx_l_sort_m_time.o \
    obj/mx_l_sort_size.o \
    obj/mx_legal_dirname.o \
    obj/mx_legal_flag.o \
    obj/mx_list_full_assembly.o \
    obj/mx_list_of_lists_size.o \
    obj/mx_make_pathname.o \
    obj/mx_number_of_dir.o \
    obj/mx_number_of_flags.o \
    obj/mx_one_column_output.o \
    obj/mx_open_dir.o \
    obj/mx_plus_insight_dir.o \
    obj/mx_print_illegal.o \
    obj/mx_print_permission_denied.o \
    obj/mx_print_wrong_dir.o \
    obj/mx_push_data_back.o \
    obj/mx_push_list_back.o \
    obj/mx_push_list_front.o \
    obj/mx_reverse_all.o \
    obj/mx_size_data_list.o \
    obj/mx_sort_a_time.o \
    obj/mx_sort_arrstr.o \
    obj/mx_sort_c_time.o \
    obj/mx_sort_datas_list.o \
    obj/mx_sort_lists_list.o \
    obj/mx_sort_m_time.o \
    obj/mx_sort_size.o \
    obj/mx_status.o \
    obj/mx_swap_data.o \
    obj/mx_swap_list.o \
    obj/mx_output_multicolumn.o \
    obj/mx_output_multicolumn_2.o \
    obj/mx_table_output.o \
    obj/mx_print_total_blocks.o \
    obj/mx_print_time.o \
    obj/mx_printnchar.o \

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install

install:
	@make -C $(LIBMXF)
	@cp $(SRCF) .
	@cp $(INCF) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) $(OBJ) $(LIBMXF)/$(LIB_NAME) -o $(APP_NAME)
	@mkdir -p ./obj
	@mv $(OBJ) ./obj
	@rm -rf $(SRC) $(INC) $(OBJ)

uninstall: clean
	@make uninstall -C $(LIBMXF)
	@rm -rf $(APP_NAME)

clean:
	@make clean -C $(LIBMXF)
	@rm -rf $(INC) $(SRC) $(OBJ)
	@rm -rf ./obj
	@rm -rf pathfinder.h.gch

reinstall: uninstall install
