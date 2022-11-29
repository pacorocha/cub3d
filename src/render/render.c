/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:29:01 by coder             #+#    #+#             */
/*   Updated: 2022/11/29 00:38:52 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_layer(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pixel_put(&data->img, j++, i, color);
		++i;
	}
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	while (i < data->nb_rows)
	{
		j = 0;
		while (j < data->nb_cols)
		{
			if (data->map[i][j] == 'L' || data->map[i][j] == '0')
				color = RED;
			if (data->map[i][j] == '1')
				color = GREEN;
			render_rect(&data->img, (t_rect){TILE_SIZE * j, TILE_SIZE  * i,
				TILE_SIZE, TILE_SIZE, color});
			j++;
		}
		i++;
	}
}

void	render_player(t_data *data)
{
	int	color;

	color = WHITE;
	render_rect(&data->img, (t_rect){data->player.x, data->player.y,
		data->player.width, data->player.height, color});
	draw_line(&data->img, (t_line){data->player.x, data->player.y,
		data->player.x + cos(data->player.rot_angle) * 10, data->player.y
		+ sin(data->player.rot_angle) * 10, WHITE});
}

void	render_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_line(&data->img, (t_line){data->player.x, data->player.y,
			data->rays[i].wall_hit_x, data->rays[i].wall_hit_y, BLUE});
		i++;
	}
}
