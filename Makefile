# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 20:49:56 by jfrancis          #+#    #+#              #
#    Updated: 2022/09/20 23:02:21 by jfrancis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

LIBFTDIR = ./libs/Libft
LIBFT = $(LIBFTDIR)/libft.a

MINILBXDIR = ./libs/minilibx-linux
MINILBX = $(MINILBXDIR)/libmlx.a

INCLUDES = -I $(MINILBXDIR) -I $(LIBFTDIR)/includes

LDLIBS = -lm -lmlx -lX11 -lbsd -lXext -lft
LDFLAGS = -L $(MINILBXDIR) -L $(LIBFTDIR)

SRCDIR = ./src

SRC =

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(MINILBX) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

$(MINILBX):
	$(MAKE) -C $(MINILBXDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJDIR)
	$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST)
	$(MAKE) clean -C $(MINILBXDIR)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re