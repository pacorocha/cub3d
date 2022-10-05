/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:29:01 by coder             #+#    #+#             */
/*   Updated: 2022/10/05 04:31:37 by coder            ###   ########.fr       */
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

int	render_game(t_data *data)
{
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
				color = RED_PIXEL;
			if (data->map[i][j] == '1')
				color = GREEN_PIXEL;
			render_rect(data, (t_rect){10 * i, 10 * j,
			10, 10, color});
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
