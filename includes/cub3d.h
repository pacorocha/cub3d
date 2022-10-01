/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:49:33 by jfrancis          #+#    #+#             */
/*   Updated: 2022/10/01 06:29:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "defines.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
} t_mlx;

typedef struct s_data
{
    int	    nb_rows;
	char	**map;
    int argc;
    char *file;
    char **cub;
	  t_mlx mlx;
    char **directions;
    char *f_color;
    char *c_color;
	int	counter;
	int	control;
} t_data;

void	init_data(t_data *data, int argc, char **argv);
int     print_error(char *msg);

//parse
void	parser(t_data *data);
void	fill_arr_textures(t_data *data, char *line, int i);
void	fill_arr_colors(t_data *data, char *line);
void	fill_map(t_data *data, char *line, int i);
void	read_map(t_data *data);
char	**lines(char *file, t_data *data);
int		check_end_of_file(char *file, char *sufx);
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