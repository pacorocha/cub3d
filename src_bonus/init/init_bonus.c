/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 03:58:24 by coder             #+#    #+#             */
/*   Updated: 2022/12/11 00:45:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	set_map_size(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
		i++;
	data->nb_rows = i;
	data->nb_cols = ft_strlen(data->map[0]);
}

int	get_player_pos(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		while (j < (int)ft_strlen(data->map[i]))
		{
			if (ft_strchr(CHAR_PLAYER, data->map[i][j]))
			{
				data->player.x = j * TILE_SIZE + (TILE_SIZE / 2);
				data->player.y = i * TILE_SIZE + (TILE_SIZE / 2);
				data->player.init_pos = data->map[i][j];
				data->map[i][j] = '0';
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

float	set_player_direction(char c)
{
	if (c == 'N')
		return (3 * PI / 2);
	else if (c == 'E')
		return (TWO_PI);
	else if (c == 'W')
		return (PI);
	else if (c == 'S')
		return (PI / 2);
	else
		return (0);
}

void	init_player(t_data *data)
{
	set_map_size(data);
	get_player_pos(data);
	data->player.rot_angle = set_player_direction(data->player.init_pos);
	data->player.width = PLAYER_SIZE;
	data->player.height = PLAYER_SIZE;
	data->player.turn_dir = 0;
	data->player.side_dir = 0;
	data->player.walk_dir = 0;
	data->player.walk_spd = 3;
	data->player.turn_spd = 3 * PI / 180;
	data->proj_plane_d = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
	data->show_map = 0;
	data->show_inst = 1;
}

void	init_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_TEX)
	{
		get_texture(data, i);
		i++;
	}
}