/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:22:48 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:22:50 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	move_player(t_data *data)
{
	float	move_step;
	float	side_step;
	float	new_player_x;
	float	new_player_y;

	data->player.rot_angle += data->player.turn_dir * data->player.turn_spd;
	normalize_angle(&data->player.rot_angle);
	side_step = data->player.side_dir * data->player.walk_spd;
	move_step = data->player.walk_dir * data->player.walk_spd;
	if (move_step && side_step)
	{
		move_step /= 2;
		side_step /= 2;
	}
	new_player_x = data->player.x + cos(data->player.rot_angle) * move_step;
	new_player_y = data->player.y + sin(data->player.rot_angle) * move_step;
	new_player_x = new_player_x - sin(-data->player.rot_angle) * side_step;
	new_player_y = new_player_y - cos(-data->player.rot_angle) * side_step;
	if (!map_has_wall_at(new_player_x, new_player_y, data))
	{
		data->player.x = new_player_x;
		data->player.y = new_player_y;
	}
}

void	update_game(t_data *data)
{
	move_player(data);
	cast_all_rays(data);
}

int	game_loop(t_data *data)
{
	update_game(data);
	render_background(data);
	init_textures(data);
	project_3d_walls(data);
	if (data->show_inst == 1)
		render_rect(&data->img, (t_rect){30, 30,
			205, 45, WHITE});
	if (data->show_map == 1)
		render_map(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win,
		data->img.img_ptr, 0, 0);
	if (data->show_inst == 1)
		render_inst(data);
	destroy_textures(data);
	return (0);
}
