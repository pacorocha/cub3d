/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:49:33 by jfrancis          #+#    #+#             */
/*   Updated: 2022/10/27 04:20:17 by jfrancis         ###   ########.fr       */
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
# include "structs.h"

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
int		key_release(int key_code, t_data *data);
int		close_window(t_data *data);

//init
int		get_player_pos(t_data *data);
void	init_player(t_data *data);
float	set_player_direction(char c);
void	set_map_size(t_data *data);

//render
void	render_map(t_data *data);
void	render_player(t_data *data);
void	render_rays(t_data *data);

// game
int		game_loop(t_data *data);

// utils
int		map_has_wall_at(float x, float y, t_data *data);
int		is_inside_map(float x, float y, t_data *data);

// raycast
void	init_ray_data(t_ray_data *ray_data);
void	init_h_data(float ray_angle, t_ray_data *h_data, t_data *data);
void	init_v_data(float ray_angle, t_ray_data *v_data, t_data *data);

void	cast_all_rays(t_data *data);
void	cast_ray(float ray_angle, int strip, t_data *data);

void	normalize_angle(float *angle);
float	distance_btw_ab(float a1, float a2, float b1, float b2);

int		is_ray_facing_down(float angle);
int		is_ray_facing_up(float angle);
int		is_ray_facing_right(float angle);
int		is_ray_facing_left(float angle);

#endif