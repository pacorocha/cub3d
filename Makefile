# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 20:49:56 by jfrancis          #+#    #+#              #
#    Updated: 2022/09/30 00:32:47 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

LIBFTDIR = libs/libft
LIBFT = $(LIBFTDIR)/libft.a

MINILBXDIR = libs/minilibx-linux
MINILBX = $(MINILBXDIR)/libmlx.a

LIBFLAGS = -lXext -lX11 -lmx
LDLIBFT = -L$(LIBFTDIR) -lft
LDMINILIBX = -L$(MINILIBX) -lmlx -lXext -lX11

#LDLIBS = -L$(LIBFTDIR)

OBJ_DIR = build
INC_DIR = includes
SRC_DIR = src
KEYS_DIR = keys

BASE =	main.c \

KEYS = keys_utils.c

SRC = $(BASE) \
		$(KEYS)

SRC_FULL = $(addprefix $(SRC_DIR)/, $(BASE)) \
			$(addprefix $(SRC_DIR)/$(KEYS_DIR)/, $(KEYS))

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FULL))

VPATH = includes \
		src src/keys \

all: $(NAME)

#$(NAME): $(OBJS) $(LIBFT)
$(NAME): $(OBJS) $(LIBFT) $(MINILBX)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBFT) $(LDMINILIBX)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(KEYS_DIR)
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