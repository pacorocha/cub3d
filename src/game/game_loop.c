/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:22:28 by jfrancis          #+#    #+#             */
/*   Updated: 2022/11/22 10:40:21 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_data *data)
{
	float	move_step;
	float	side_step;
	float	new_player_x;
	float	new_player_y;

	data->player.rot_angle += data->player.turn_dir * data->player.turn_spd;
	normalize_angle(&data->player.rot_angle);
	side_step = data->player.side_dir * data->player.walk_spd;
	move_step = data->player.walk_dir * data->player.walk_spd;
	if (move_step && side_step)
	{
		move_step /= 2;
		side_step /= 2;
	}
	new_player_x = data->player.x + cos(data->player.rot_angle) * move_step;
	new_player_y = data->player.y + sin(data->player.rot_angle) * move_step;
	new_player_x = new_player_x - sin(-data->player.rot_angle) * side_step;
	new_player_y = new_player_y - cos(-data->player.rot_angle) * side_step;
	if (!map_has_wall_at(new_player_x, new_player_y, data))
	{
		data->player.x = new_player_x;
		data->player.y = new_player_y;
	}
}

void	update_game(t_data *data)
{
	move_player(data);
	cast_all_rays(data);
}

int	game_loop(t_data *data)
{
	update_game(data);
	render_layer(data, RED);
	render_background(data);
	// render_map(data);
	// render_rays(data);
	// render_player(data);
	render_texture(data);
	project_3d_walls(data);

	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win,
		data->img.img_ptr, 0, 0);
	return (0);
}

void    render_texture(t_data *data)
{
    //ha uma função da minilibx q pega pixel por pixel
    // int    i;
    // int    j;

	// t_img text;

	// data->texture = malloc(sizeof(int *) * (int)TEX_WIDTH * (int)TEX_HEIGHT);

	data->texture.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr, "./wall_texture.xpm", &data->texture.width, &data->texture.height);
	data->texture.pixels = mlx_get_data_addr(data->texture.img_ptr, &data->texture.bpp, &data->texture.line_len, &data->texture.endian);

	// i = 0;

    /* while (i < TEX_HEIGHT)
    {
        j = 0;
        while (j < TEX_WIDTH)
        {
            // if (i % 8 && j % 8)
            //     data->texture[TEX_WIDTH * i + j] = 0xFF0000FF;
            // else
            //     data->texture[TEX_WIDTH * i + j] = 0xFF000000;

			//color_pixel = verify_color(data);
			data->texture[TEX_WIDTH * i + j] = text.pixels[i * TEX_WIDTH + j];
            j++;
        }
        i++;
    } */
}

