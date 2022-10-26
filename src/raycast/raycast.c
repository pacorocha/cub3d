/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:45:07 by coder             #+#    #+#             */
/*   Updated: 2022/10/26 04:08:23 by jfrancis         ###   ########.fr       */
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
			h_data->y_to_check -= 1;
		if (map_has_wall_at(h_data->x_to_check, h_data->y_to_check, data))
		{
			h_data->wall_hit_x = h_data->next_touch_x;
			h_data->wall_hit_y = h_data->next_touch_y;
			h_data->hit_d = distance_btw_ab(data->player.x, data->player.y,
				h_data->wall_hit_x, h_data->wall_hit_y);
			h_data->wall_content = data->map[(int)floor(h_data->y_to_check
				/ TILE_SIZE)][(int)floor(h_data->x_to_check / TILE_SIZE)];
			h_data->found_wall = FALSE;
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
			v_data->hit_d = distance_btw_ab(data->player.x, data->player.y,
				v_data->wall_hit_x, v_data->wall_hit_y);
			v_data->wall_content = data->map[(int)floor(v_data->y_to_check
				/ TILE_SIZE)][(int)floor(v_data->x_to_check / TILE_SIZE)];
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
	if (v_data.hit_d < h_data.hit_d)
	{
		data->rays[strip].distance = v_data.hit_d;
		data->rays[strip].wall_hit_x = v_data.wall_hit_x;
		data->rays[strip].wall_hit_y = v_data.wall_hit_y;
		data->rays[strip].was_hit_vert = TRUE;
		data->rays[strip].ray_angle = ray_angle;
	}
	else
	{
		data->rays[strip].distance = h_data.hit_d;
		data->rays[strip].wall_hit_x = h_data.wall_hit_x;
		data->rays[strip].wall_hit_y = h_data.wall_hit_y;
		data->rays[strip].was_hit_vert = FALSE;
		data->rays[strip].ray_angle = ray_angle;
	}
}

void	cast_all_rays(t_data *data)
{
	float	ray_angle;
	int		strip;

	strip = 0;
	ray_angle = normalize_angle(data->player.rot_angle - (FOV_ANGLE / 2));
	while (strip < NUM_RAYS)
	{
		ray_angle += FOV_ANGLE / NUM_RAYS;
		ray_angle = normalize_angle(ray_angle);
		cast_ray(ray_angle, strip, data);
		strip++;
	}
}
