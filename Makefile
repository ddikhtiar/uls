APP_NAME = uls

LIBMXF = libmx

LIB_NAME = libmx.a

INC = uls.h

INCF = inc/uls.h

SRC = \
    main.c \
    mx_check_arr_dir.c \
    mx_check_flags_conflict.c \
    mx_create_data.c \
    mx_create_flags_struct.c \
    mx_create_list.c \
    mx_dir_arr.c \
    mx_fill_buffer.c \
    mx_find_flag.c \
    mx_flags_arr.c \
    mx_for_dir_to_list.c \
    mx_legal_dirname.c \
    mx_legal_flag.c \
    mx_list_assembly.c \
    mx_make_pathname.c \
    mx_number_of_dir.c \
    mx_number_of_flags.c \
    mx_open_dir.c \
    mx_plus_insight_dir.c \
    mx_print_illegal.c \
    mx_print_wrong_dir.c \
    mx_push_data_back.c \
    mx_push_list_back.c \
    mx_push_list_front.c \
    mx_sort_arrstr.c \
    mx_status.c \
    mx_swap_data.c \
    mx_swap_list.c \
    mx_output_multicolumn.c \

SRCF = \
    src/main.c \
    src/mx_check_arr_dir.c \
    src/mx_check_flags_conflict.c \
    src/mx_create_data.c \
    src/mx_create_flags_struct.c \
    src/mx_create_list.c \
    src/mx_dir_arr.c \
    src/mx_fill_buffer.c \
    src/mx_find_flag.c \
    src/mx_flags_arr.c \
    src/mx_for_dir_to_list.c \
    src/mx_legal_dirname.c \
    src/mx_legal_flag.c \
    src/mx_list_assembly.c \
    src/mx_make_pathname.c \
    src/mx_number_of_dir.c \
    src/mx_number_of_flags.c \
    src/mx_open_dir.c \
    src/mx_plus_insight_dir.c \
    src/mx_print_illegal.c \
    src/mx_print_wrong_dir.c \
    src/mx_push_data_back.c \
    src/mx_push_list_back.c \
    src/mx_push_list_front.c \
    src/mx_sort_arrstr.c \
    src/mx_status.c \
    src/mx_swap_data.c \
    src/mx_swap_list.c \
    src/mx_output_multicolumn.c \

OBJ = $(SRC:.c=.o)

OBJO = \
    obj/main.o \
    obj/mx_check_arr_dir.o \
    obj/mx_check_flags_conflict.o \
    obj/mx_create_data.o \
    obj/mx_create_flags_struct.o \
    obj/mx_create_list.o \
    obj/mx_dir_arr.o \
    obj/mx_fill_buffer.o \
    obj/mx_find_flag.o \
    obj/mx_flags_arr.o \
    obj/mx_for_dir_to_list.o \
    obj/mx_legal_dirname.o \
    obj/mx_legal_flag.o \
    obj/mx_list_assembly.o \
    obj/mx_make_pathname.o \
    obj/mx_number_of_dir.o \
    obj/mx_number_of_flags.o \
    obj/mx_open_dir.o \
    obj/mx_plus_insight_dir.o \
    obj/mx_print_illegal.o \
    obj/mx_print_wrong_dir.o \
    obj/mx_push_data_back.o \
    obj/mx_push_list_back.o \
    obj/mx_push_list_front.o \
    obj/mx_sort_arrstr.o \
    obj/mx_status.o \
    obj/mx_swap_data.o \
    obj/mx_swap_list.o \
    obj/mx_output_multicolumn.o \

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
