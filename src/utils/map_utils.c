/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:21:08 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:21:09 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_has_wall_at(float x, float y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (x < 0 || x > ft_strlen(data->map[map_y]) * TILE_SIZE || y < 0
		|| (int)y > data->nb_rows * TILE_SIZE)
	{
		return (FALSE);
	}
	return (data->map[map_y][map_x] != '0' && data->map[map_y][map_x] != 'L');
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

void	count_col(t_data *data, int i)
{
	while (data->cub[i] != NULL)
	{
		if (ft_strlen(data->cub[i]) > data->big_line)
			data->big_line = ft_strlen(data->cub[i]);
		i++;
	}
	if (data->big_line < 3)
	{
		free_minimun_lines_map(data);
		print_error("Error, line < 3");
	}
}
