/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:49:33 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 22:59:37 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "defines_bonus.h"
# include "structs_bonus.h"

void	init_data(t_data *data, int argc, char **argv);
int		print_error(char *msg);
void	error_colors(t_data *data);
void	verification_of_rgb_color(t_data *data, int i, char **rgb);

//parse
void	parser(t_data *data);
void	fill_arr_textures(t_data *data, char *line);
void	fill_arr_colors(t_data *data, char *line);
void	fill_map(t_data *data, char *line, int i);
void	read_map(t_data *data);
char	**lines(char *file, t_data *data);
void	check_fd_map(int fd, char *file);
int		check_end_of_file(char *file, char *sufx);
void	fill_structures_loop(t_data *data);
void	check_rgb_char(t_data *data, char **rgb_arr, char rgb_char, char *rgb);
void	add_char_lines(t_data *data);
void	verification_char_line(t_data *data, char *line);

//map_checker
void	map_checker(t_data *data);
int		is_invalid(char **arr_split);
void	verification_sides_of_char(t_data *data, int row, size_t col);
void	char_change(t_data *data, int row, size_t col, char new_color);
void	checking_sides(t_data *data, int row, size_t col);
void	search_ocurrence_ground(t_data *data);
void	flood_fill(t_data *data, int row, size_t col);
void	count_col(t_data *data, int i);
void	checking_color(t_data *data);
void	check_color(t_data *data, char *color);
int		is_open(t_data *data, int row, size_t col);
int		is_space(char c);
void	checking_texture(t_data *data);
int		is_invalid_file_texture(char *texture);
void	checking_texture(t_data *data);
void	check_dup_textures(t_data *data);
void	get_map(t_data *data, int i);
void	have_player(t_data *data, char c_current);

//utils parse
void	check_flags_directions(t_data *data, char *line, int counter);
void	check_flags_colors(t_data *data, char *line);

//free
void	free_array(char **arr);
void	free_array(char **arr);
void	free_checker(t_data *data);
void	free_textures(t_data *data, int num_tex);
void	free_minimun_lines_map(t_data *data);

//keys
int		key_press(int key_code, t_data *data);
void	map_keys(t_data *data, int key_code);
int		key_release(int key_code, t_data *data);
int		close_window(t_data *data);

//init
int		get_player_pos(t_data *data);
void	init_player(t_data *data);
float	set_player_direction(char c);
void	set_map_size(t_data *data);

//render
void	project_3d_walls(t_data *data);
void	process_wall_textures(t_data *data, t_wall *wall, int y, int i);
void	render_background(t_data *data);
int		render_rect(t_img *img, t_rect rect);
void	render_map(t_data *data);
void	render_inst(t_data *data);
void	render_player(t_data *data);
void	distance_effect(t_data *data, t_wall *wall, int i);
void	wall_orientation(t_data *data, t_wall *wall, int i);
void	darken_color(int *color, float factor);

// game
int		game_loop(t_data *data);

// utils
int		map_has_wall_at(float x, float y, t_data *data);
int		is_inside_map(float x, float y, t_data *data);
void	draw_line(t_img *img, t_line line);
void	img_pixel_put(t_img *img, int x, int y, int color);
int		get_color(char *color);
void	destroy_textures(t_data *data);
void	init_img(t_data *data, t_img *img, int width, int heigth);

//textures
void	init_textures(t_data *data);
void	map_texture(t_data *data, int i, char *texture);
void	get_texture(t_data *data, int i);

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