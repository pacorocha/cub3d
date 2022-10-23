/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:27:11 by coder             #+#    #+#             */
/*   Updated: 2022/10/23 03:46:00 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_data(t_ray_data *ray_data)
{
	ray_data->found_wall = FALSE;
	ray_data->wall_hit_x = 0;
	ray_data->wall_hit_y = 0;
	ray_data->wall_content = 0;
	ray_data->hit_d = FLT_MAX;
}

void	init_h_data(float ray_angle, t_ray_data *h_data, t_data *data)
{
	init_ray_data(h_data);
	h_data->y_intercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_down(ray_angle))
		h_data->y_intercept += TILE_SIZE;
	h_data->x_intercept = data->player.x
		+ (h_data->y_intercept - data->player.y) / tan(ray_angle);
	h_data->y_step = TILE_SIZE;
	if (is_ray_facing_up(ray_angle))
		h_data->y_step *= -1;
	h_data->x_step = TILE_SIZE / tan(ray_angle);
	if (is_ray_facing_left(ray_angle) && h_data->x_step > 0)
		h_data->x_step *= -1;
	if (is_ray_facing_right(ray_angle) && h_data->x_step < 0)
		h_data->x_step *= -1;
	h_data->next_touch_x = h_data->x_intercept;
	h_data->next_touch_y = h_data->y_intercept;
}

void	init_v_data(float ray_angle, t_ray_data *v_data, t_data *data)
{
	init_ray_data(v_data);
	v_data->x_intercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_right(ray_angle))
		v_data->x_intercept += TILE_SIZE;
	v_data->y_intercept = data->player.y
		+ (v_data->x_intercept - data->player.x) * tan(ray_angle);
	v_data->x_step = TILE_SIZE;
	if (is_ray_facing_left(ray_angle))
		v_data->x_step *= -1;
	v_data->y_step = TILE_SIZE * tan(ray_angle);
	if ((is_ray_facing_up(ray_angle) && v_data->y_step > 0))
		v_data->y_step *= 1;
	if ((is_ray_facing_down(ray_angle) && v_data->y_step < 0))
		v_data->y_step *= -1;
	v_data->next_touch_x = v_data->x_intercept;
	v_data->next_touch_y = v_data->y_intercept;
}
