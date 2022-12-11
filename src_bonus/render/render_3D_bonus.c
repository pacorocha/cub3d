/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3D_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:25:17 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:25:19 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	darken_color(int *color, float factor)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = (*color & 0xFF000000);
	r = (*color & 0x00FF0000) * factor;
	g = (*color & 0x0000FF00) * factor;
	b = (*color & 0x000000FF) * factor;
	*color = a | (r & 0x00FF0000) | (g & 0x0000FF00) | (b & 0x000000FF);
}

static void	define_wall_size(t_wall *wall)
{
	if (wall->wall_top < 0)
		wall->wall_top = 0;
	if (wall->wall_bottom > WIN_HEIGHT)
		wall->wall_bottom = WIN_HEIGHT;
}

void	project_3d_walls(t_data *data)
{
	int		i;
	int		y;
	t_wall	*wall;

	i = 0;
	wall = malloc(sizeof(t_wall));
	while (i < NUM_RAYS)
	{
		wall->perp_d = data->rays[i].distance * cos(data->rays[i].ray_angle
				- data->player.rot_angle);
		wall->projd_wall_h = (TILE_SIZE / wall->perp_d) * data->proj_plane_d;
		wall->strip_wall_h = (int)wall->projd_wall_h;
		wall->wall_top = (WIN_HEIGHT / 2) - (wall->strip_wall_h / 2);
		wall->wall_bottom = (WIN_HEIGHT / 2) + (wall->strip_wall_h / 2);
		define_wall_size(wall);
		y = wall->wall_top;
		if (data->rays[i].was_hit_vert)
			wall->tex_offset_x = (int)data->rays[i].wall_hit_y % TILE_SIZE;
		else
			wall->tex_offset_x = (int)data->rays[i].wall_hit_x % TILE_SIZE;
		process_wall_textures(data, wall, y, i);
		i++;
	}
	free(wall);
}

void	process_wall_textures(t_data *data, t_wall *wall, int y, int i)
{
	while (y < wall->wall_bottom)
	{
		wall->d_from_top = y + (wall->strip_wall_h / 2) - (WIN_HEIGHT / 2);
		wall->tex_offset_y
			= wall->d_from_top * ((float)TEX_HEIGHT / wall->strip_wall_h);
		wall_orientation(data, wall, i);
		distance_effect(data, wall, i);
		if (data->rays[i].was_hit_vert)
			darken_color(&wall->color, 0.7);
		img_pixel_put(&data->img, i, y, wall->color);
		y++;
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
