/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:45:07 by coder             #+#    #+#             */
/*   Updated: 2022/10/19 05:17:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_h_data(float ray_angle, t_ray_data *h_data, t_data *data)
{
	init_h_data(ray_angle, h_data, data);
	
	while (is_inside_map(h_data->next_touch_x, h_data->next_touch_y, data))
	{
		h_data->x_to_check = h_data->next_touch_x;
		h_data->y_to_check = h_data->next_touch_y;
		if (is_ray_facing_up(ray_angle))
			h_data->y_to_check -= -1;
		if (map_has_wall_at(h_data->x_to_check, h_data->y_to_check, data))
		{
			h_data->wall_hit_x = h_data->next_touch_x;
			h_data->wall_hit_y = h_data->next_touch_y;
			h_data->wall_content = data->map[(int)floor(h_data->y_to_check / TILE_SIZE)][(int)floor(h_data->x_to_check / TILE_SIZE)];
			h_data->found_wall = TRUE;
			break ;
		}
		else
		{
			h_data->next_touch_x += h_data->x_step;
			h_data->next_touch_y += h_data->y_step;
		}
	}
}

void	check_v_data(float ray_angle, t_ray_data *v_data, t_data *data)
{
	init_v_data(ray_angle, v_data, data);
	while (is_inside_map(v_data->next_touch_x, v_data->next_touch_y, data))
	{
		v_data->x_to_check = v_data->next_touch_x;
		v_data->y_to_check = v_data->next_touch_y;
		if (is_ray_facing_left(ray_angle))
			v_data->x_to_check -= 1;
		if (map_has_wall_at(v_data->x_to_check, v_data->y_to_check, data))
		{
			v_data->wall_hit_x = v_data->next_touch_x;
			v_data->wall_hit_y = v_data->next_touch_y;
			v_data->wall_content = data->map[(int)floor(v_data->y_to_check / TILE_SIZE)][(int)floor(v_data->x_to_check / TILE_SIZE)];
			v_data->found_wall = TRUE;
			break ;
		}
		else
		{
			v_data->next_touch_x += v_data->x_step;
			v_data->next_touch_y += v_data->y_step;
		}
	}
}

void	cast_ray(float ray_angle, int strip, t_data *data)
{
	t_ray_data	h_data;
	t_ray_data	v_data;
	
	check_h_data(ray_angle, &h_data, data);
	check_v_data(ray_angle, &v_data, data);
	printf("%i", strip);
}

void	cast_all_rays(t_data *data)
{
	float	ray_angle;
	int		strip;

	strip = 0;
	ray_angle = data->player.rot_angle - (FOV_ANGLE / 2);
	while (strip < NUM_RAYS)
	{
		cast_ray(ray_angle, strip, data);
		normalize_angle(ray_angle);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		strip++;
	}
}
