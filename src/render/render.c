/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:29:01 by coder             #+#    #+#             */
/*   Updated: 2022/10/27 05:31:59 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

static void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void draw_line(t_img *img, float beginX, float beginY, float endX, float endY, int color)
{
	float deltaX = endX - beginX; // 10
	float deltaY = endY - beginY; // 0

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		img_pixel_put(img, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pixel_put(img, j++, i, color);
		++i;
	}
}

int	render_rect(t_img *img, t_rect rect)
{
	int i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void render_map(t_data *data) {
	int i;
	int j;
	int color;

	i = 0;
	j = 0;
	while (i < data->nb_rows)
	{
		j = 0;
		while (j < data->nb_cols)
		{
			if (data->map[i][j] == '0')
				color = RED;
			if (data->map[i][j] == '1')
				color = GREEN;
			render_rect(&data->img, (t_rect){TILE_SIZE * j,  TILE_SIZE * i,
				 TILE_SIZE,  TILE_SIZE, color});
			j++;
		}
		i++;
	}
}

void	render_player(t_data *data)
{
	int color;
	color = WHITE;
	render_rect(&data->img, (t_rect){data->player.x, data->player.y,
		data->player.width, data->player.height, color});
	// a linha é helper, apagar depois
	draw_line(&data->img, data->player.x, data->player.y, data->player.x + cos(data->player.rot_angle) * 10, data->player.y + sin(data->player.rot_angle) * 10, WHITE);
}

void render_rays(t_data *data)
{
	int i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_line(&data->img, data->player.x, data->player.y, data->rays[i].wall_hit_x, data->rays[i].wall_hit_y, BLUE);
		i++;
	}
}
