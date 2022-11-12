/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:38:02 by jfrancis          #+#    #+#             */
/*   Updated: 2022/11/12 02:40:23 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	project_3d_walls(t_data *data)
{
	int	i;
	int	y;
	int	strip_wall_h;
	int	wall_top;
	int	wall_bottom;
	float	proj_plane_d;
	float	projd_wall_h;

	i = 0;
	proj_plane_d = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		projd_wall_h = (TILE_SIZE / data->rays[i].distance) * proj_plane_d;
		strip_wall_h = (int)projd_wall_h;
		wall_top = (WIN_HEIGHT / 2) - (strip_wall_h / 2);
		wall_bottom = (WIN_HEIGHT / 2) + (strip_wall_h / 2);
		if (wall_top < 0)
			wall_top = 0;
		y = wall_top;
		if (wall_bottom > WIN_HEIGHT)
			wall_bottom = WIN_HEIGHT;
		while (y < wall_bottom)
		{
			img_pixel_put(&data->img, i, y, WHITE);
			y++;
		}
		i++;
	}
}
