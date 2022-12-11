/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_extras_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:25:26 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:25:27 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

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
	int	y;
	int	x;
	int	color;
	int	scale_f;

	y = 0;
	x = 0;
	scale_f = TILE_SIZE / 8;
	while (y < data->nb_rows)
	{
		x = 0;
		while (x < data->nb_cols)
		{
			if (data->map[y][x] == '0' || data->map[y][x] == 'L')
				color = BLACK;
			if (data->map[y][x] == '1' || data->map[y][x] == ' ')
				color = WHITE;
			render_rect(&data->img, (t_rect){scale_f * x, scale_f * y,
				scale_f, scale_f, color});
			x++;
		}
		y++;
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

void	render_inst(t_data *data)
{
	char	*inst_one;
	char	*inst_two;

	inst_one = "Press E to open and close map.";
	inst_two = "Press I to close this message.";
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win, 45, 47, BLACK,
		inst_one);
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win, 45, 62, BLACK,
		inst_two);
}

void	distance_effect(t_data *data, t_wall *wall, int i)
{
	float	color_factor;

	if (FOG_DIST && data->rays[i].distance > FOG_DIST)
	{
		color_factor = FOG_DIST / data->rays[i].distance;
		darken_color(&wall->color, color_factor);
	}
}
