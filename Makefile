##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## Compile the project
##

CC			:=	epiclang

RM			=	rm -f

NAME    	=	wolf3d

LIBMY_FILES			=	minidprintf.c	\
						my_pow.c		\
						my_round.c		\
						my_strcmp.c		\
						my_strlen.c		\
						my_strncmp.c	\
						my_strtol.c		\
						my_strdup.c		\
						get_flags.c		\
						get_index.c

LIBGRAPHICS_FILES	=	destroy_game.c		\
						display_game.c		\
						init_game.c			\
						main_loop.c			\
						update_game.c		\
						entity_functions.c	\
						button_functions.c	\
						is_clicked.c		\
						display_env_exist.c	\
						load_ressource.c

SRC_FILES	=	$(addprefix libmy/, $(LIBMY_FILES))				\
				$(addprefix libgraphics/, $(LIBGRAPHICS_FILES))	\
				main.c

SRC			=	$(addprefix src/, $(SRC_FILES))	\

OBJ			=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -fno-builtin

CPPFLAGS	+=	-iquote ./include

DEBUG_FLAGS	=	-g3

LDFLAGS		+=	-lcsfml-graphics	\
				-lcsfml-window		\
				-lcsfml-system		\
				-lcsfml-audio		\
				-lm

UT_SRC		=	$(addprefix src/, $(SRC_FILES)) \

UT_NAME		=	unit_tests

UT_FLAGS	=	--coverage -lcriterion -Wno-div-by-zero -lgcov

COVR_FLAGS	=	--exclude tests/ --gcov-ignore-errors=no_working_dir_found	\
				--gcov-executable "llvm-cov-20 gcov"

VALGR_FLAGS	=	-s --leak-check=full

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)	$(LDFLAGS)

clean:
	@$(RM) $(OBJ)
	@$(RM) "*.gcda"
	@$(RM) "*.gcno"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(UT_NAME)

re: fclean all

debug:	CFLAGS += $(DEBUG_FLAGS)
debug:	re

memory_check: debug
	@valgrind $(VALGR_FLAGS) ./$(NAME)

tests_run: clean
	@clang -o $(UT_NAME) $(UT_SRC) $(UT_FLAGS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
	./$(UT_NAME)

coverage: tests_run
	gcovr $(COVR_FLAGS)
	@$(RM) "*.gcda"
	@$(RM) "*.gcno"
	@$(RM) $(UT_NAME)

.PHONY:
	all			\
	clean		\
	fclean		\
	re			\
	debug		\
	test_run	\
	coverage	\
