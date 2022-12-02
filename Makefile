# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 20:49:56 by jfrancis          #+#    #+#              #
#    Updated: 2022/12/01 23:58:46 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
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
INC_DIR = includes
SRC_DIR = src
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

SRC = $(BASE) \
		$(KEYS) \
		$(INIT) \
		$(RENDER) \
		$(GAME) \
		$(UTILS) \
		$(RAYCAST) \
		$(PARSER) \
		$(READER_MAP) \

SRC_FULL = $(addprefix $(SRC_DIR)/, $(BASE)) \
			$(addprefix $(SRC_DIR)/$(KEYS_DIR)/, $(KEYS)) \
			$(addprefix $(SRC_DIR)/$(INIT_DIR)/, $(INIT)) \
			$(addprefix $(SRC_DIR)/$(RENDER_DIR)/, $(RENDER)) \
			$(addprefix $(SRC_DIR)/$(GAME_DIR)/, $(GAME)) \
			$(addprefix $(SRC_DIR)/$(UTILS_DIR)/, $(UTILS)) \
			$(addprefix $(SRC_DIR)/$(RAYCAST_DIR)/, $(RAYCAST)) \
			$(addprefix $(SRC_DIR)/$(PARSER_DIR)/, $(PARSER)) \
			$(addprefix $(SRC_DIR)/$(READER_MAP_DIR)/, $(READER_MAP)) \

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FULL))

VPATH = includes \
		src src/keys \
		src/init \
		src/render \
		src/game \
		src/utils \
		src/raycast \
		src/parser \
		src/reader_map \


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILBX)
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

re: fclean all

.PHONY: all clean fclean re