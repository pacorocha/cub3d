/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 03:06:08 by coder             #+#    #+#             */
/*   Updated: 2022/12/10 17:53:08 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_ray_data
{
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;
	int		found_wall;
	float	wall_hit_x;
	float	wall_hit_y;
	float	wall_color;
	int		wall_content;
	float	next_touch_x;
	float	next_touch_y;
	float	x_to_check;
	float	y_to_check;
	float	hit_d;
}	t_ray_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_line
{
	float	x_one;
	float	y_one;
	float	x_two;
	float	y_two;
	int		color;
}	t_line;

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vert;
	int		wall_hit_content;
}	t_ray;

typedef struct s_wall
{
	int		strip_wall_h;
	int		wall_top;
	int		wall_bottom;
	int		color;
	int		tex_offset_x;
	int		tex_offset_y;
	int		d_from_top;
	float	projd_wall_h;
	float	perp_d;
}	t_wall;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	int		bpp;
	char	*pixels;
	int		*colors;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		color;
	void	*img_ptr;
	char	*path;
	char	*id;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	float	view_angle;
	int		turn_dir;
	int		walk_dir;
	int		side_dir;
	float	rot_angle;
	float	walk_spd;
	float	turn_spd;
	char	init_pos;
}	t_player;

typedef struct s_specs
{
	int	c_rgb;
	int	f_rgb;
}	t_specs;

typedef struct s_data
{
	int			nb_rows;
	int			nb_cols;
	char		**map;
	int			argc;
	char		*file;
	char		**cub;
	t_specs		specs;
	t_mlx		mlx;
	t_player	player;
	t_img		img;
	t_ray		rays[NUM_RAYS];
	t_img		*textures[NUM_TEX];
	t_img		mini_map;
	char		**directions;
	char		*f_color;
	char		*c_color;
	int			counter_flow;
	int			counter_map;
	int			control;
	size_t		big_line;
	float		proj_plane_d;
	int			show_map;
	int			show_inst;
	int			num_player;
}	t_data;

#endif