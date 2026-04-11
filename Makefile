##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## Compile the project
##

CC			:=	epiclang

RM			=	rm -f

NAME    	=	wolf3d

LIB_FILES	=

SRC_FILES	=	$(addprefix lib/, $(LIB_FILES))	\

SRC			=	$(addprefix src/, $(SRC_FILES))	\

OBJ			=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra

CPPFLAGS	+=	-iquote ./include

DEBUG_FLAGS	=	-g3

LDFLAGS		+=

UT_SRC		=	$(addprefix src/, $(SRC_FILES)) \

UT_NAME		=	unit_tests

UT_FLAGS	=	--coverage -lcriterion -Wno-div-by-zero -lgcov

COVR_FLAGS	=	--exclude tests/ --gcov-ignore-errors=no_working_dir_found	\
				--gcov-executable "llvm-cov-20 gcov"

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

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
