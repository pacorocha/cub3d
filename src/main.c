/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:40:13 by jfrancis          #+#    #+#             */
/*   Updated: 2022/09/24 03:26:27 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	init_data(&data, argc, argv);
	parser(&data);
	data.mlx.mlx_ptr = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx_ptr, 1024, 620, "Haunted House");
	mlx_hook(data.mlx.win, 33, 1L << 17, close_window, &data);
	mlx_key_hook(data.mlx.win, &key_press, &data);
	mlx_loop(data.mlx.mlx_ptr);
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->argc = argc;
	data->file = argv[1];
}

void	parser(t_data *data)
{
	if (data->argc != 2)
		print_error("ERROR!\nNumber of parameters is invalid!\n");

	check_textures(data);

}

void	check_textures(t_data *data)
{
	int content;
	int	gnl;
	int	i;

	data->map = lines(data->file, data);
	content = open(data->file, O_RDONLY);
	gnl = 1;
	i = 0;
	while (gnl)
		gnl = get_next_line(content, &data->map[i++]);
	data->map[i] = NULL;

	i = 0;
	while(data->map[i] != NULL)
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	close(content);
}

char	**lines(char *file, t_data *data)
{
	int		fd;
	int		read_line;
	char	c;
	int		nb_rows;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (NULL);
	if (!check_file(file, "cub"))
		print_error("Every map must have a .cub extension\n");
	nb_rows = 0;
	read_line = 1;
	while (read_line)
	{
		read_line = read(fd, &c, 1);
		if (read_line < 0)
			return (NULL);
		if (c == '\n')
			nb_rows++;
	}
	close(fd);
	data->map = (char **)ft_calloc(nb_rows, sizeof(char *));
	return (data->map);
}

int	check_file(char *file, char *sufx)
{
	int	counter;

	counter = 0;
	while (file[counter + 1])
		counter++;
	while (counter >= 0 && file[counter] != '.')
		counter--;
	if (counter >= 0 && !ft_strcmp(file + counter + 1, sufx))
		return (1);
	return (0);
}

int	print_error(char *msg)
{
	printf("%s\n", msg);
	return (FALSE);
}



