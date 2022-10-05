/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 03:06:08 by coder             #+#    #+#             */
/*   Updated: 2022/10/05 03:47:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	float	fov_angle;
	int		turn_dir;
	int		walk_dir;
	float	rot_angle;
	float	walk_spd;
	float	turn_spd;
	char	init_pos;
}	t_player;

typedef struct s_data
{
	int			nb_rows;
	int			nb_cols;
	char		**map;
	int			argc;
	char		*file;
	char		**cub;
	t_mlx		mlx;
	t_player	player;
	char		**directions;
	char		*f_color;
	char		*c_color;
	int			counter;
	int			control;
}	t_data;

#endif