/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dmonteir < dmonteir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:49:33 by jfrancis          #+#    #+#             */
/*   Updated: 2022/09/24 01:58:11 by Dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include"../libs/libft/libft.h"

# define TRUE 1
# define FALSE 0


typedef struct t_data
{
    int argc;
    char *file;
    char **map;
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

#endif