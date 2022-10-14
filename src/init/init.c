/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 03:58:24 by coder             #+#    #+#             */
/*   Updated: 2022/10/14 02:34:35 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	data->player.walk_spd = 1;
	data->player.turn_spd = 5 * PI / 180;
}
