/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 03:28:55 by jfrancis          #+#    #+#             */
/*   Updated: 2022/10/23 03:31:55 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_has_wall_at(float x, float y, t_data *data)
{
	int	map_x;
	int	map_y;

	if (x < 0 || x >= data->nb_cols * TILE_SIZE || y < 0 || y > data->nb_rows * TILE_SIZE)
	{
		return (FALSE);
	}
	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	return (data->map[map_y][map_x] != '0');
}

int	is_inside_map(float x, float y, t_data *data)
{
	if (x >= 0 && x <= data->nb_cols * TILE_SIZE
		&& y >= 0 && y <= data->nb_rows * TILE_SIZE)
	{
		return (TRUE);
	}
	return (FALSE);
}
