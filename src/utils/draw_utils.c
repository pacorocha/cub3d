/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:04:01 by jfrancis          #+#    #+#             */
/*   Updated: 2022/11/16 21:39:44 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	draw_line(t_img *img, t_line line)
{
	float	delta_x;
	float	delta_y;
	float	pixel_x;
	float	pixel_y;
	int		pixels;

	delta_x = line.x_two - line.x_one;
	delta_y = line.y_two - line.y_one;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = line.x_one;
	pixel_y = line.y_one;
	while (pixels)
	{
		img_pixel_put(img, pixel_x, pixel_y, line.color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

int	get_color(char *color)
{
	char **rgb;
	int i_rgb;

	rgb = ft_split(color, ',');
	i_rgb = 0;
	i_rgb += (ft_atoi(rgb[0]) & 0xFF) << 16;
	i_rgb += (ft_atoi(rgb[1]) & 0XFF) << 8;
	i_rgb += (ft_atoi(rgb[2]) & 0XFF);
	return (i_rgb);
}
