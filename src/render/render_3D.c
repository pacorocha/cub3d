/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:38:02 by jfrancis          #+#    #+#             */
/*   Updated: 2022/11/22 10:40:39 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	project_3d_walls(t_data *data)
{
	int		i;
	int		y;
	int		strip_wall_h;
	int		wall_top;
	int		wall_bottom;
	int		color;
	int		tex_offset_x;
	int		tex_offset_y;
	int		d_from_top;
	float	proj_plane_d;
	float	projd_wall_h;
	float	perp_d;

	i = 0;
	proj_plane_d = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		perp_d = data->rays[i].distance * cos(data->rays[i].ray_angle
			- data->player.rot_angle);
		projd_wall_h = (TILE_SIZE / perp_d) * proj_plane_d;
		strip_wall_h = (int)projd_wall_h;
		wall_top = (WIN_HEIGHT / 2) - (strip_wall_h / 2);
		wall_bottom = (WIN_HEIGHT / 2) + (strip_wall_h / 2);
		if (wall_top < 0)
			wall_top = 0;
		y = wall_top;
		if (wall_bottom > WIN_HEIGHT)
			wall_bottom = WIN_HEIGHT;


		//texture
		if (data->rays[i].was_hit_vert)
			tex_offset_x = (int)data->rays[i].wall_hit_y % TILE_SIZE;
		else
			tex_offset_x = (int)data->rays[i].wall_hit_x % TILE_SIZE;

		while (y < wall_bottom)
		{
			d_from_top = y + (strip_wall_h / 2) - (WIN_HEIGHT / 2);
			tex_offset_y = d_from_top * ((float)TEX_HEIGHT / strip_wall_h);
			color = data->texture.pixels[(TEX_WIDTH * tex_offset_y) + tex_offset_x];
			img_pixel_put(&data->img, i, y, color);
			y++;
		}
		i++;
	}
}

void	render_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT / 2)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pixel_put(&data->img, j++, i, data->specs.c_rgb);
		++i;
	}
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pixel_put(&data->img, j++, i, data->specs.f_rgb);
		++i;
	}
}
