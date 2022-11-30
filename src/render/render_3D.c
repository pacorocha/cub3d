/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:38:02 by jfrancis          #+#    #+#             */
/*   Updated: 2022/11/30 19:52:34 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	wall->proj_plane_d = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		wall->perp_d = data->rays[i].distance * cos(data->rays[i].ray_angle
				- data->player.rot_angle);
		wall->projd_wall_h = (TILE_SIZE / wall->perp_d) * wall->proj_plane_d;
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
}

void	process_wall_textures(t_data *data, t_wall *wall, int y, int i)
{
	while (y < wall->wall_bottom)
	{
		wall->d_from_top = y + (wall->strip_wall_h / 2) - (WIN_HEIGHT / 2);
		wall->tex_offset_y
			= wall->d_from_top * ((float)TEX_HEIGHT / wall->strip_wall_h);
		if (!data->rays[i].was_hit_vert
			&& is_ray_facing_up(data->rays[i].ray_angle))
				wall->color = data->textures[0]->colors[((TEX_WIDTH)
					* wall->tex_offset_y) + wall->tex_offset_x];
		if (!data->rays[i].was_hit_vert
			&& is_ray_facing_down(data->rays[i].ray_angle))
				wall->color = data->textures[1]->colors[((TEX_WIDTH)
					* wall->tex_offset_y) + wall->tex_offset_x];
		if (data->rays[i].was_hit_vert
			&& is_ray_facing_left(data->rays[i].ray_angle))
			wall->color = data->textures[2]->colors[((TEX_WIDTH)
					* wall->tex_offset_y) + wall->tex_offset_x];
		if (data->rays[i].was_hit_vert
			&& is_ray_facing_right(data->rays[i].ray_angle))
			wall->color = data->textures[3]->colors[((TEX_WIDTH)
					* wall->tex_offset_y) + wall->tex_offset_x];
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
