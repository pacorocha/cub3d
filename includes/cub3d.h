/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:49:33 by jfrancis          #+#    #+#             */
/*   Updated: 2022/09/24 03:42:05 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"

# define TRUE 1
# define FALSE 0

# define KEY_ESC (0xff1b)
# define KEY_Q (0x71)

# define KEY_A (0x61)
# define KEY_S (0x73)
# define KEY_D (0x64)
# define KEY_W (0x77)

# define KEY_UP (0xff52)
# define KEY_DOWN (0xff54)
# define KEY_LEFT (0xff51)
# define KEY_RIGHT (0xff53)

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
} t_mlx;

typedef struct s_data
{
    int argc;
    char *file;
    char **map;
	t_mlx mlx;
} t_data;

void	init_data(t_data *data, int argc, char **argv);

//parse
void	parser(t_data *data);
void	check_textures(t_data *data);
int     print_error(char *msg);
char	**lines(char *file, t_data *data);
int	    check_file(char *file, char *sufx);

//keys
int		key_press(int key_code, t_data *data);
int		close_window(t_data *data);

#endif