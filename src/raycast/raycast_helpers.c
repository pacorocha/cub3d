/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:19:34 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:19:36 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_ray_facing_down(float angle)
{
	return (angle > 0 && angle < PI);
}

int	is_ray_facing_up(float angle)
{
	return (!is_ray_facing_down(angle));
}

int	is_ray_facing_right(float angle)
{
	return (angle < PI * 0.5 || angle > 1.5 * PI);
}

int	is_ray_facing_left(float angle)
{
	return (!is_ray_facing_right(angle));
}
