/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 03:09:43 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 00:44:09 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
	free_checker(data);
	free_textures(data, NUM_TEX);
	exit(0);
	return (0);
}

int	key_press(int key_code, t_data *data)
{
	if (key_code == KEY_ESC || key_code == KEY_Q)
		close_window(data);
	if (key_code == KEY_W)
		data->player.walk_dir = +1;
	if (key_code == KEY_S)
		data->player.walk_dir = -1;
	if (key_code == KEY_D)
		data->player.side_dir = -1;
	if (key_code == KEY_A)
		data->player.side_dir = +1;
	if (key_code == KEY_RIGHT)
		data->player.turn_dir = +1;
	if (key_code == KEY_LEFT)
		data->player.turn_dir = -1;
	map_keys(data, key_code);
	return (0);
}

void	map_keys(t_data *data, int key_code)
{
	if (key_code == KEY_E)
	{
		if (data->show_map == 0)
			data->show_map = 1;
		else
			data->show_map = 0;
		if (data->show_inst == 1)
			data->show_inst = 0;
	}
	if (key_code == KEY_I)
	{
		if (data->show_inst == 1)
			data->show_inst = 0;
		else
			data->show_inst = 1;
	}
}

int	key_release(int key_code, t_data *data)
{
	if (key_code == KEY_W)
		data->player.walk_dir = 0;
	if (key_code == KEY_S)
		data->player.walk_dir = 0;
	if (key_code == KEY_D)
		data->player.side_dir = 0;
	if (key_code == KEY_A)
		data->player.side_dir = 0;
	if (key_code == KEY_RIGHT)
		data->player.turn_dir = 0;
	if (key_code == KEY_LEFT)
		data->player.turn_dir = 0;
	return (0);
}
