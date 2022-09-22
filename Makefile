# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Dmonteir < dmonteir@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 20:49:56 by jfrancis          #+#    #+#              #
#    Updated: 2022/09/23 01:13:29 by Dmonteir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

LIBFTDIR = libs/libft
LIBFT = $(LIBFTDIR)/libft.a

# MINILBXDIR = libs/minilibx-linux
# MINILBX = $(MINILBXDIR)/libmlx.a

LIBFLAGS = -lm -lbsd -lmlx -lXext -lX11
#LDLIBS = -L$(MINILBXDIR) -L$(LIBFTDIR)
LDLIBS = -L$(LIBFTDIR)

OBJ_DIR = build
INC_DIR = includes

BASE = main.c

SRC = $(BASE)

SRC_FULL = $(addprefix $(SRC_DIR)/, $(BASE))

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FULL))

VPATH = includes \
		src

all: $(NAME)

#$(NAME): $(OBJS) $(MINILBX) $(LIBFT)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# $(MINILBX):
# 	$(MAKE) -C $(MINILBXDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFTDIR)
# $(MAKE) clean -C $(MINILBXDIR)

fclean: clean
	$(RM) $(NAME)
# $(MAKE) clean -C $(MINILBXDIR)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re