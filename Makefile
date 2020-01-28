APP_NAME = uls

LIBMXF = libmx

LIB_NAME = libmx.a

INC = uls.h

INCF = inc/uls.h

SRC = \
    main.c \
    mx_check_arr_dir.c \
    mx_create_data.c \
    mx_create_flags_struct.c \
    mx_create_list.c \
    mx_dir_arr.c \
    mx_fill_buffer.c \
    mx_find_flag.c \
    mx_flags_arr.c \
    mx_legal_dirname.c \
    mx_legal_flag.c \
    mx_list_assembly.c \
    mx_list_current_dir.c \
    mx_number_of_dir.c \
    mx_number_of_flags.c \
    mx_print_illegal.c \
    mx_print_wrong_dir.c \
    mx_push_data_back.c \
    mx_push_list_back.c \
    mx_push_list_front.c \
    mx_status.c \

SRCF = \
    src/main.c \
    src/mx_check_arr_dir.c \
    src/mx_create_data.c \
    src/mx_create_flags_struct.c \
    src/mx_create_list.c \
    src/mx_dir_arr.c \
    src/mx_fill_buffer.c \
    src/mx_find_flag.c \
    src/mx_flags_arr.c \
    src/mx_legal_dirname.c \
    src/mx_legal_flag.c \
    src/mx_list_assembly.c \
    src/mx_list_current_dir.c \
    src/mx_number_of_dir.c \
    src/mx_number_of_flags.c \
    src/mx_print_illegal.c \
    src/mx_print_wrong_dir.c \
    src/mx_push_data_back.c \
    src/mx_push_list_back.c \
    src/mx_push_list_front.c \
    src/mx_status.c \

OBJ = $(SRC:.c=.o)

OBJO = \
    obj/main.o \
    obj/mx_check_arr_dir.o \
    obj/mx_create_data.o \
    obj/mx_create_flags_struct.o \
    obj/mx_create_list.o \
    obj/mx_dir_arr.o \
    obj/mx_fill_buffer.o \
    obj/mx_find_flag.o \
    obj/mx_flags_arr.o \
    obj/mx_legal_dirname.o \
    obj/mx_legal_flag.o \
    obj/mx_list_assembly.o \
    obj/mx_list_current_dir.o \
    obj/mx_number_of_dir.o \
    obj/mx_number_of_flags.o \
    obj/mx_print_illegal.o \
    obj/mx_print_wrong_dir.o \
    obj/mx_push_data_back.o \
    obj/mx_push_list_back.o \
    obj/mx_push_list_front.o \
    obj/mx_status.o \

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
