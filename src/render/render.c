/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:29:01 by coder             #+#    #+#             */
/*   Updated: 2022/10/07 00:10:12 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

int render_rect(t_data *data, t_rect rect)
{
	int	i;
	int j;

	if (data->mlx.win == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.win, j++, i, rect.color);
		++i;
	}
	return (0);
}

void render_map(t_data *data) {
	int i;
	int j;
	int color;

	i = 0;
	j = 0;
	while (i < data->nb_rows)
	{
		while (j < data->nb_cols)
		{
			if (data->map[i][j] == '0')
				color = RED;
			if (data->map[i][j] == '1')
				color = GREEN;
			render_rect(data, (t_rect){16 * i, 16 * j,
				16, 16, color});
			j++;
		}
		j = 0;
		i++;
	}
	color = BlACK;
	render_rect(data, (t_rect){data->player.x, data->player.y,
		data->player.width, data->player.height, color});

}

int	render_game(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render_map(data);
	return (0);
}
