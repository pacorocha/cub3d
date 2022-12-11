/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:25:34 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:25:36 by jfrancis         ###   ########.fr       */
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
