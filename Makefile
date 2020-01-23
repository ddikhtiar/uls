APP_NAME = uls

LIBMXF = libmx

LIB_NAME = libmx.a

INC = uls.h

INCF = inc/uls.h

SRC = \
main.c \
mx_filenames.c \
mx_create_flags_struct.c \
mx_dir_arr.c \
mx_find_flag.c \
mx_flags_arr.c \
mx_legal_flag.c \
mx_number_of_dir.c \
mx_number_of_flags.c \
mx_print_illegal.c \
mx_data_factory.c \
mx_list_factory.c \
# mx_flags_out.c \

SRCF = \
src/main.c \
src/mx_filenames.c \
src/mx_create_flags_struct.c \
src/mx_dir_arr.c \
src/mx_find_flag.c \
src/mx_flags_arr.c \
src/mx_legal_flag.c \
src/mx_number_of_dir.c \
src/mx_number_of_flags.c \
src/mx_print_illegal.c \
src/mx_data_factory.c \
src/mx_list_factory.c \
# src/mx_flags_out.c \

OBJ = \
main.o \
mx_filenames.o \
mx_create_flags_struct.o \
mx_dir_arr.o \
mx_find_flag.o \
mx_flags_arr.o \
mx_legal_flag.o \
mx_number_of_dir.o \
mx_number_of_flags.o \
mx_print_illegal.o \
mx_data_factory.o \
mx_list_factory.o \
# mx_flags_out.o \

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C $(LIBMXF)
	@cp $(SRCF) .
	@cp $(INCF) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) $(OBJ) $(LIBMXF)/$(LIB_NAME) -o $(APP_NAME)
	@mkdir -p ./obj
	@mv $(OBJ) ./obj

uninstall:
	@make uninstall -C $(LIBMXF)
	@rm -rf $(APP_NAME)

clean:
	@make clean -C $(LIBMXF)
	@rm -rf $(INC)
	@rm -rf $(SRC)
	@rm -rf ./obj
	@rm -rf pathfinder.h.gch

reinstall: uninstall all
