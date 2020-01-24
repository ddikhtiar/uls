APP_NAME = uls

LIBMXF = libmx

LIB_NAME = libmx.a

INC = uls.h

INCF = inc/uls.h

SRC = \
    main.c \
    mx_check_arr_dir.c \
    mx_create_flags_struct.c \
    mx_data_factory.c \
    mx_dir_arr.c \
    mx_get_filenames.c \
    mx_find_flag.c \
    mx_flags_arr.c \
    mx_legal_dirname.c \
    mx_legal_flag.c \
    mx_list_factory.c \
    mx_number_of_dir.c \
    mx_number_of_flags.c \
    mx_print_illegal.c \
    mx_print_wrong_dir.c \
    mx_status.c \

SRCF = \
    src/main.c \
    src/mx_check_arr_dir.c \
    src/mx_create_flags_struct.c \
    src/mx_data_factory.c \
    src/mx_dir_arr.c \
    src/mx_get_filenames.c \
    src/mx_find_flag.c \
    src/mx_flags_arr.c \
    src/mx_legal_dirname.c \
    src/mx_legal_flag.c \
    src/mx_list_factory.c \
    src/mx_number_of_dir.c \
    src/mx_number_of_flags.c \
    src/mx_print_illegal.c \
    src/mx_print_wrong_dir.c \
    src/mx_status.c \

OBJ = $(SRC:.c=.o)

OBJO = \
    obj/main.o \
    obj/mx_check_arr_dir.o \
    obj/mx_create_flags_struct.o \
    obj/mx_data_factory.o \
    obj/mx_dir_arr.o \
    obj/mx_get_filenames.o \
    obj/mx_find_flag.o \
    obj/mx_flags_arr.o \
    obj/mx_legal_dirname.o \
    obj/mx_legal_flag.o \
    obj/mx)mx_list_factory.o \
    obj/mx_number_of_dir.o \
    obj/mx_number_of_flags.o \
    obj/mx_print_illegal.o \
    obj/mx_print_wrong_dir.o \
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
