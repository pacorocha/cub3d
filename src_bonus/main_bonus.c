/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:40:13 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 21:54:42 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data, argc, argv);
	read_map(&data);
	parser(&data);
	init_player(&data);
	data.mlx.mlx_ptr = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"Haunted House");
	data.img.img_ptr = mlx_new_image(data.mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.img.pixels = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_hook(data.mlx.win, 33, 1L << 17, close_window, &data);
	mlx_hook(data.mlx.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, &game_loop, &data);
	mlx_loop(data.mlx.mlx_ptr);
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->argc = argc;
	data->counter_flow = 0;
	data->file = argv[1];
	data->c_color = NULL;
	data->f_color = NULL;
	data->control = 0;
	data->control_color = 0;
	data->counter_map = 0;
	data->num_player = 0;
	data->big_line = 0;
	data->map = NULL;
}
