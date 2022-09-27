/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dmonteir < dmonteir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:49:33 by jfrancis          #+#    #+#             */
/*   Updated: 2022/09/28 00:49:12 by Dmonteir         ###   ########.fr       */
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
    char **directions;
    char *f_color;
    char *c_color;
} t_data;

void	init_data(t_data *data, int argc, char **argv);
int     print_error(char *msg);

//parse
void	parser(t_data *data);

void	fill_arr_textures(t_data *data, char *line, int i);
void	fill_arr_colors(t_data *data, char *line);
void	read_map(t_data *data);
char	**lines(char *file, t_data *data);
int	    check_file(char *file, char *sufx);
void	loop_check(t_data *data);

//utils parse
int     check_flags_cardinal_directions(char *line);
int     check_flags_colors(char *line);

//free
void	free_array(char **arr);

//keys
int		key_press(int key_code, t_data *data);
int		close_window(t_data *data);

#endif