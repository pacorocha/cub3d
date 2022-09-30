/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:40:13 by jfrancis          #+#    #+#             */
/*   Updated: 2022/10/01 03:52:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	init_data(&data, argc, argv);
	read_map(&data);

	parser(&data);
	// data.mlx.mlx_ptr = mlx_init();
	// data.mlx.win = mlx_new_window(data.mlx.mlx_ptr, 1024, 620, "Haunted House");
	// mlx_hook(data.mlx.win, 33, 1L << 17, close_window, &data);
	// mlx_key_hook(data.mlx.win, &key_press, &data);
	// mlx_loop(data.mlx.mlx_ptr);
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->argc = argc;
	data->counter = 0;
	data->file = argv[1];
	data->c_color = NULL;
	data->f_color = NULL;
	data->control = 0;
}

void	parser(t_data *data)
{
	if (data->argc != 2)
		print_error("ERROR!\nNumber of parameters is invalid!\n");
	
	loop_check(data);
	

}

void	loop_check(t_data *data)
{
	int i;
	
	i = 0;
	while(data->cub[i] != NULL)
	{
		if (data->cub[i][0] != '\0')
		{
			if (check_flags_cardinal_directions(data->cub[i]))
			{
				fill_arr_textures(data, data->cub[i], i);
				data->counter++;
			}
			else if (check_flags_colors(data->cub[i]))
			{
				fill_arr_colors(data, data->cub[i]);
				data->counter++;
			}
			else
				fill_map(data, data->cub[i], i);
		}
		i++;
	}

	// i = 0;
	// while(data->map[i] != NULL)
	// {
	// 	printf("%s\n", data->map[i]);
	// 	i++;
	// }
}

void	fill_map(t_data *data, char *line, int i)
{
	if (data->counter == 6 && data->control == 0)
	{
		data->counter = 0;
		
		data->nb_rows = data->nb_rows - i;
		data->map = (char **)ft_calloc(data->nb_rows + 1, sizeof(char *));
		data->map[data->counter] = ft_strdup(line);
	}
	else
	{
		data->counter++;
		data->map[data->counter] = ft_strdup(line);
		data->control = 1;
	}
	if(data->counter == data->nb_rows - 1)
	{
		data->map[data->counter + 1] = NULL;
		data->control = 1;
	}
}

void	fill_arr_textures(t_data *data, char *line, int i)
{
	if (i == 0)
	{
		data->directions = (char **)ft_calloc(5, sizeof(char *));		
		data->directions[i] = line;
	}
	else
		data->directions[i] = line;

	if (i == 3)
		data->directions[i + 1] = NULL;
}

void	fill_arr_colors(t_data *data, char *line)
{
	char **str_splitted;

	str_splitted = ft_split(line, ' ');
	if (!ft_strncmp(line, "F ", 2))
		data->f_color = ft_strdup(str_splitted[1]);
	else
		data->c_color = ft_strdup(str_splitted[1]);
	
	free(str_splitted);
}

void	read_map(t_data *data)
{
	int content;
	int	gnl;
	int	i;

	data->cub = lines(data->file, data);
	content = open(data->file, O_RDONLY);
	gnl = 1;
	i = 0;
	while (gnl)
		gnl = get_next_line(content, &data->cub[i++]);
	data->cub[i] = NULL;
	//count_nb_col(data);
	//game->col = (ft_strlen(game->cub[0]) - 1);
	close(content);
}

void	free_array(char **arr)
{
	int i;

	i = 0;
	while ((arr)[i])
	{
		free((arr)[i]);
		i++;
	}
	free(arr);
}

int	check_end_of_file(char *file, char *sufx)
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

int	check_flags_cardinal_directions(char *line)
{
	if (!ft_strncmp(line, "NO", 2) ||
	!ft_strncmp(line, "SO", 2) ||
	!ft_strncmp(line, "WE", 2) ||
	!ft_strncmp(line, "EA", 2))
		return (1);

	return (0);
}

int	check_flags_colors(char *line)
{
	if (!ft_strncmp(line, "F ", 2) ||
	!ft_strncmp(line, "C ", 2))
		return (1);

	return (0);
}

char	**lines(char *file, t_data *data)
{
	int		fd;
	int		read_line;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (NULL);
	if (!check_end_of_file(file, "cub"))
		print_error("Every map must have a .cub extension\n");
	data->nb_rows = 1;
	read_line = 1;
	while (read_line)
	{
		read_line = read(fd, &c, 1);
		if (read_line < 0)
			return (NULL);
		if (c == '\n')
			data->nb_rows++;
	}
	close(fd);
	data->cub = (char **)ft_calloc(data->nb_rows + 1, sizeof(char *));
	return (data->cub);
}

int	print_error(char *msg)
{
	printf("%s\n", msg);
	return (FALSE);
}