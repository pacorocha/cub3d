/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 03:58:24 by coder             #+#    #+#             */
/*   Updated: 2022/10/04 03:59:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_map_size(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	data->nb_rows = i;
}

int	get_player_pos(t_data *data)
{
	int		i;
	int		j;
	char	*char_player;

	i = 0;
	j = 0;
	char_player = "NSWE";
	while (data->map[i] != NULL)
	{
		while (j < (int)ft_strlen(data->map[i]))
		{
			if (ft_strchr(char_player, data->map[i][j]))
			{
				data->player.x = j * TILE_SIZE + (TILE_SIZE / 2);
				data->player.y = i * TILE_SIZE + (TILE_SIZE / 2);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	init_player(t_data *data)
{
	set_map_size(data);
	get_player_pos(data);
}
