/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 03:06:08 by coder             #+#    #+#             */
/*   Updated: 2022/10/11 02:45:55 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	int		bpp;
	char	*addr;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		color;
	void	*img_ptr;
	int		*dump;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	float	fov_angle;
	int		turn_dir;
	int		walk_dir;
	int		side_dir;
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
	t_img		img;
	char		**directions;
	char		*f_color;
	char		*c_color;
	int			counter;
	int			control;
}	t_data;

#endif