##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## Compile the project
##

CC			:=	epiclang

SRC_DIR		:=	src
OBJ_DIR		:=	build

RM			:=	rm -f

NAME    	:=	wolf3d

RAYCAST_FILES		=	castray.c			\
						draw_world.c		\
						draw_walls.c		\
						struct_manip.c

LIBGRAPHICS_FILES	=	destroy_game.c		\
						display_game.c		\
						init_game.c			\
						main_loop.c			\
						update_game.c		\
						entity_functions.c	\
						button_functions.c	\
						is_clicked.c		\
						display_env_exist.c	\
						update_player.c

EVENTS_FILES		=	analyse_events.c 	\
						key_event.c			\
						player_move_stop.c 	\
						player_move.c		\
						go_to_menu_scene.c 	\
						player_rotation.c 	\
						handle_buttons_click.c

SRC_FILES	=	$(addprefix libgraphics/, $(LIBGRAPHICS_FILES))	\
				$(addprefix events/, $(EVENTS_FILES))\
				$(addprefix raycast/, $(RAYCAST_FILES))

SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))	\
				$(SRC_DIR)/main.c

OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS		+=	-Wall -Wextra -fno-builtin

CPPFLAGS	+=	-iquote ./include -iquote ./include/my

DEBUG_FLAGS	=	-g3

LDFLAGS		+=	-lcsfml-graphics	\
				-lcsfml-window		\
				-lcsfml-system		\
				-lcsfml-audio		\
				-lm

UT_SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES)) \

UT_NAME		=	unit_tests

UT_FLAGS	=	--coverage -lcriterion -Wno-div-by-zero -lgcov

COVR_FLAGS	=	--exclude tests/ --gcov-ignore-errors=no_working_dir_found	\
				--gcov-executable "llvm-cov-20 gcov"

VALGR_FLAGS	=	-s --leak-check=full

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ)	$(LDFLAGS)

$(OBJ_DIR):
	rsync -a --include='*/' --exclude='*' $(SRC_DIR)/ $(OBJ_DIR)/

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -o $@ -c $^ $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	@$(RM) *.gcda
	@$(RM) *.gcno

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
	@$(RM) *.gcda
	@$(RM) *.gcno
	@$(RM) $(UT_NAME)

.PHONY:
	all			\
	clean		\
	fclean		\
	re			\
	debug		\
	test_run	\
	coverage	\
