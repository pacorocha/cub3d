/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_helpers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:24:42 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:24:44 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

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
