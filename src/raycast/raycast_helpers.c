/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 02:59:17 by coder             #+#    #+#             */
/*   Updated: 2022/10/19 02:59:50 by coder            ###   ########.fr       */
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
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

int	is_ray_facing_left(float angle)
{
	return (!is_ray_facing_right(angle));
}
