# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 20:49:56 by jfrancis          #+#    #+#              #
#    Updated: 2022/12/11 01:20:13 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
RM = rm -rf

LIBFTDIR = libs/libft
LIBFT = $(LIBFTDIR)/libft.a

MINILBXDIR = libs/minilibx-linux
MINILBX = $(MINILBXDIR)/libmlx.a

LDLIBFT = -L$(LIBFTDIR) -lft -lm
LDMINILIBX = -L$(MINILIBX) -lmlx -lXext -lX11

OBJ_DIR = build
OBJ_BONUS = build_bonus
INC_DIR = includes
INC_BONUS = includes_bonus
SRC_DIR = src
BONUS_DIR = src_bonus
KEYS_DIR = keys
INIT_DIR = init
RENDER_DIR = render
GAME_DIR = game
UTILS_DIR = utils
RAYCAST_DIR = raycast
PARSER_DIR = parser
READER_MAP_DIR = reader_map

BASE =	main.c \

KEYS = keys_utils.c \

INIT = init.c \

RENDER = render_3D.c \

RENDER_BONUS =	render_3D_bonus.c \
				render_extras_bonus.c \
				render_wall_bonus.c \

GAME = game_loop.c \

UTILS = map_utils.c \
		error_utils.c \
		free_utils.c \
		read_utils.c \
		draw_utils.c \

RAYCAST = raycast.c \
		raycast_math.c \
		raycast_helpers.c \
		raycast_init.c

PARSER = check_flags.c \
		checker.c \
		filling.c \
		flood_fill_checker.c \
		flood_fill_utils.c \
		checker_utils.c \

READER_MAP = read_map.c \

BASE_BONUS = main_bonus.c \

KEYS_BONUS = keys_utils_bonus.c \

INIT_BONUS = init_bonus.c \

GAME_BONUS = game_loop_bonus.c \

UTILS_BONUS = map_utils_bonus.c \
		error_utils_bonus.c \
		free_utils_bonus.c \
		read_utils_bonus.c \
		draw_utils_bonus.c \

RAYCAST_BONUS = raycast_bonus.c \
		raycast_math_bonus.c \
		raycast_helpers_bonus.c \
		raycast_init_bonus.c

PARSER_BONUS = check_flags_bonus.c \
		checker_bonus.c \
		filling_bonus.c \
		flood_fill_checker_bonus.c \
		flood_fill_utils_bonus.c \
		checker_utils_bonus.c \

READER_MAP_BONUS = read_map_bonus.c \

SRC = $(BASE) \
		$(KEYS) \
		$(INIT) \
		$(RENDER) \
		$(GAME) \
		$(UTILS) \
		$(RAYCAST) \
		$(PARSER) \
		$(READER_MAP) \

SRC_BONUS = $(BASE_BONUS) \
		$(KEYS_BONUS) \
		$(INIT_BONUS) \
		$(RENDER_BONUS) \
		$(GAME_BONUS) \
		$(UTILS_BONUS) \
		$(RAYCAST_BONUS) \
		$(PARSER_BONUS) \
		$(READER_MAP_BONUS) \

SRC_FULL = $(addprefix $(SRC_DIR)/, $(BASE)) \
			$(addprefix $(SRC_DIR)/$(KEYS_DIR)/, $(KEYS)) \
			$(addprefix $(SRC_DIR)/$(INIT_DIR)/, $(INIT)) \
			$(addprefix $(SRC_DIR)/$(RENDER_DIR)/, $(RENDER)) \
			$(addprefix $(SRC_DIR)/$(GAME_DIR)/, $(GAME)) \
			$(addprefix $(SRC_DIR)/$(UTILS_DIR)/, $(UTILS)) \
			$(addprefix $(SRC_DIR)/$(RAYCAST_DIR)/, $(RAYCAST)) \
			$(addprefix $(SRC_DIR)/$(PARSER_DIR)/, $(PARSER)) \
			$(addprefix $(SRC_DIR)/$(READER_MAP_DIR)/, $(READER_MAP)) \

SRC_FULL_BONUS = $(addprefix $(BONUS_DIR)/, $(BASE_BONUS)) \
			$(addprefix $(BONUS_DIR)/$(KEYS_DIR)/, $(KEYS_BONUS)) \
			$(addprefix $(BONUS_DIR)/$(INIT_DIR)/, $(INIT_BONUS)) \
			$(addprefix $(BONUS_DIR)/$(RENDER_DIR)/, $(RENDER_BONUS)) \
			$(addprefix $(BONUS_DIR)/$(GAME_DIR)/, $(GAME_BONUS)) \
			$(addprefix $(BONUS_DIR)/$(UTILS_DIR)/, $(UTILS_BONUS)) \
			$(addprefix $(BONUS_DIR)/$(RAYCAST_DIR)/, $(RAYCAST_BONUS)) \
			$(addprefix $(BONUS_DIR)/$(PARSER_DIR)/, $(PARSER_BONUS)) \
			$(addprefix $(BONUS_DIR)/$(READER_MAP_DIR)/, $(READER_MAP_BONUS))

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FULL))
OBJS_BONUS = $(patsubst $(SRC_BONUS)/%.c, $(OBJ_BONUS)/%.o, $(SRC_FULL_BONUS))

VPATH = includes \
		src src/keys \
		src/init \
		src/render \
		src/game \
		src/utils \
		src/raycast \
		src/parser \
		src/reader_map \
		includes_bonus \
		src_bonus src_bonus/keys \
		src_bonus/init \
		src_bonus/render \
		src_bonus/game \
		src_bonus/utils \
		src_bonus/raycast \
		src_bonus/parser \
		src_bonus/reader_map \

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT) $(MINILBX)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBFT) $(LDMINILIBX)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(MINILBX)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBFT) $(LDMINILIBX)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(KEYS_DIR)
	mkdir -p $(OBJ_DIR)/$(INIT_DIR)
	mkdir -p $(OBJ_DIR)/$(RENDER_DIR)
	mkdir -p $(OBJ_DIR)/$(GAME_DIR)
	mkdir -p $(OBJ_DIR)/$(UTILS_DIR)
	mkdir -p $(OBJ_DIR)/$(RAYCAST_DIR)
	mkdir -p $(OBJ_DIR)/$(PARSER_DIR)
	mkdir -p $(OBJ_DIR)/$(READER_MAP_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_BONUS)/%.o: $(SRC_BONUS)/%.c
	mkdir -p $(OBJ_BONUS)
	mkdir -p $(OBJ_BONUS)/$(KEYS_DIR)
	mkdir -p $(OBJ_BONUS)/$(INIT_DIR)
	mkdir -p $(OBJ_BONUS)/$(RENDER_DIR)
	mkdir -p $(OBJ_BONUS)/$(GAME_DIR)
	mkdir -p $(OBJ_BONUS)/$(UTILS_DIR)
	mkdir -p $(OBJ_BONUS)/$(RAYCAST_DIR)
	mkdir -p $(OBJ_BONUS)/$(PARSER_DIR)
	mkdir -p $(OBJ_BONUS)/$(READER_MAP_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_BONUS)

$(MINILBX):
	$(MAKE) -C $(MINILBXDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MINILBXDIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) clean -C $(MINILBXDIR)
	$(MAKE) fclean -C $(LIBFTDIR)

clean_bonus:
	$(RM) $(OBJ_BONUS)
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MINILBXDIR)

fclean_bonus: clean_bonus
	$(RM) $(NAME_BONUS)
	$(MAKE) clean -C $(MINILBXDIR)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re bonus