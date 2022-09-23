/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dmonteir < dmonteir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:49:33 by jfrancis          #+#    #+#             */
/*   Updated: 2022/09/23 01:01:06 by Dmonteir         ###   ########.fr       */
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


typedef struct s_data
{
    int argc;
    char *file;
    char **map;
	t_mlx mlx;
} t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
} t_mlx;

void	init_data(t_data *data, int argc, char **argv);

//parse
void	parser(t_data *data);
void	check_textures(t_data *data);
int     print_error(char *msg);
char	**lines(char *file, t_data *data);
int	    check_file(char *file, char *sufx);

#endif