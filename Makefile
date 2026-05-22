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

LIBMY_FILES			=	get_flags.c			\
						get_index.c			\
						print_array.c		\
						free_array.c		\
						str_to_array.c		\
						check_array_malloc.c\
						arraylen.c			\
						concat_string.c		\
						get_field_value.c	\
						file_to_str.c		\
						is_sep.c			\
						load_map.c

RAYCAST_FILES		=	castray.c			\
						draw_world.c		\
						draw_walls.c		\
						struct_manip.c		\
						shading.c

LIBGRAPHICS_FILES	=	counters/update_counters.c			\
						counters/update_stamina.c			\
						counters/update_fps.c				\
						counters/update_score_text.c		\
						\
						texts/update_text.c 				\
						\
						game/destroy_game.c					\
						game/display_game.c					\
						game/init_game.c					\
						game/main_loop.c					\
						game/update_game.c					\
						game/apply_settings.c				\
						game/save_system.c					\
						game/display_env_exist.c			\
						\
						objects/button_functions.c			\
						\
						ressources/load_ressource.c			\
						ressources/get_config_function.c	\
						ressources/get_ressource.c			\
						\
						objects/create_text.c				\
						objects/create_window.c				\
						objects/create_sprite.c				\
						objects/text_function.c				\
						objects/center_text_on_sprite.c		\
						\
						update/update_player.c				\
						\
						animations/animations_functions.c

EVENTS_FILES		=	analyse_events.c 		\
						is_hovered.c			\
						key_event.c				\
						player_move_stop.c 		\
						player_move.c			\
						go_to_menu_scene.c 		\
						player_rotation.c 		\
						player_sprint.c 		\
						player_flashlight.c 	\
						handle_buttons_click.c	\
						player_interact.c		\
						settings_buttons.c		\
						on_click_functions.c

LIBLIST_FILES		=	add_node.c			\
						array_to_list.c		\
						delete_node.c		\
						display_list.c		\
						free_list.c			\
						list_len.c			\
						file_to_list.c

SRC_FILES	=	$(addprefix libmy/, $(LIBMY_FILES))				\
				$(addprefix graphics/, $(LIBGRAPHICS_FILES))	\
				$(addprefix list/, $(LIBLIST_FILES))			\
				$(addprefix events/, $(EVENTS_FILES))			\
				$(addprefix raycast/, $(RAYCAST_FILES))

SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))	\
				$(SRC_DIR)/main.c

OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS		+=	-Wall -Wextra -fno-builtin

CPPFLAGS	+=	-iquote ./include -iquote ./include/my

DEBUG_FLAGS	=	-g3
GPROF_FLAGS =	-pg

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
	@$(RM) -r $(OBJ_DIR)

re: fclean all

debug:	CFLAGS += $(DEBUG_FLAGS)
debug:	re

prof:	CFLAGS += $(GPROF_FLAGS)
prof:	LDFLAGS += $(GPROF_FLAGS)
prof:	re
	./$(NAME)
	gprof $(NAME)

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
	prof 		\
	debug		\
	test_run	\
	coverage	\
