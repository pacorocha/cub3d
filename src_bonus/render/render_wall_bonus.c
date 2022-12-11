/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:39:31 by coder             #+#    #+#             */
/*   Updated: 2022/12/11 00:48:14 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	wall_orientation(t_data *data, t_wall *wall, int i)
{
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
}
