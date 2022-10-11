# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 20:49:56 by jfrancis          #+#    #+#              #
#    Updated: 2022/10/11 02:24:54 by jfrancis         ###   ########.fr        #
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

BASE =	main.c \

KEYS = keys_utils.c \

INIT = init.c \

RENDER = render.c \

GAME = game_loop.c \

SRC = $(BASE) \
		$(KEYS) \
		$(INIT) \
		$(RENDER) \
		$(GAME)

SRC_FULL = $(addprefix $(SRC_DIR)/, $(BASE)) \
			$(addprefix $(SRC_DIR)/$(KEYS_DIR)/, $(KEYS)) \
			$(addprefix $(SRC_DIR)/$(INIT_DIR)/, $(INIT)) \
			$(addprefix $(SRC_DIR)/$(RENDER_DIR)/, $(RENDER)) \
			$(addprefix $(SRC_DIR)/$(GAME_DIR)/, $(GAME))

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FULL))

VPATH = includes \
		src src/keys \
		src/init \
		src/render \
		src/game


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILBX)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBFT) $(LDMINILIBX)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(KEYS_DIR)
	mkdir -p $(OBJ_DIR)/$(INIT_DIR)
	mkdir -p $(OBJ_DIR)/$(RENDER_DIR)
	mkdir -p $(OBJ_DIR)/$(GAME_DIR)
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