/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:40:13 by jfrancis          #+#    #+#             */
/*   Updated: 2022/10/27 01:12:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	init_data(&data, argc, argv);
	read_map(&data);
	parser(&data);
	// init_player(&data);
	// data.mlx.mlx_ptr = mlx_init();
	// data.mlx.win = mlx_new_window(data.mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Haunted House");
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
	data->big_line = 0;
}

void	parser(t_data *data)
{
	if (data->argc != 2)
		print_error("ERROR!\nNumber of parameters is invalid!\n");
	fill_structures_loop(data);
	count_col(data);
	add_char_lines(data);
	map_checker(data);
}

void	add_char_lines(t_data *data)
{
	int i;
	size_t j;
	size_t	len_num;
	
	i = 0;
	while(data->map[i] != NULL)
	{
		j = 0;
		len_num = data->big_line + 1;
		while (j < len_num)
		{
			if (ft_strlen(data->map[i]) <= len_num)
				ft_strlcat(data->map[i], "D", len_num);
			j++;
		}
		
		i++;
	}

}

void	count_col(t_data *data)
{
	int	i;

	i = 0;
	while(data->map[i] != NULL)
	{
		if (ft_strlen(data->map[i]) > data->big_line)
			data->big_line = ft_strlen(data->map[i]);
		i++;
	}
	if (data->big_line < 3)
		print_error("Map Invalid!! Please choose a map valid!!!");
}

void	map_checker(t_data *data)
{
	//checking_texture(data);
	checking_color(data);
	search_ocurrence_ground(data);
	
}


void	checking_color(t_data *data)
{
	check_color(data->f_color);
	check_color(data->c_color);
}

void	check_color(char *color)
{
	char **rgb;
	int	i;
	int	j;
	int	is_num;
	int len_num;

	i = 0;
	rgb = ft_split(color, ',');
	while(rgb[i] != NULL)
	{
		j = 0;
		len_num = ft_strlen(rgb[i]);
		while (j < len_num)
		{
			is_num = ft_isdigit(rgb[i][j]);
			if (!is_num)
				print_error("Invalid color!! Choose a possible color from the RGB scale.");
			if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
				print_error("Invalid color!! Choose a possible color from the RGB scale.");
			j++;
		}
		i++;
	}
	if (i < 3)
		print_error("Invalid color!! Choose a possible color from the RGB scale.");
}

void	search_ocurrence_ground(t_data *data)
{
	int i;
	size_t j;
	size_t len_col;


	i = 0;
	data->control = 0;
	while(i < data->nb_rows - 1)
	{
		printf("Linha tal: %i\n", i);
		j = 0;
		len_col = ft_strlen(data->map[i]);
		while(j < len_col)
		{
			printf("Coluna tal: %zu\n", j);
			if (data->map[i][j] == '0')
			{
				data->control = 1;
				break ;
			}		
			j++;
		}
		if (data->control == 1)
			break ;
		i++;
	}

	init_flood_fill(data, i, j);
	i = 0;

	while (i < data->nb_rows)
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}

void	init_flood_fill(t_data *data, int row, size_t col)
{
	char	new_color;
	char	prev_color;

	new_color = 'L';
	prev_color = '0';
	data->big_line = ft_strlen(data->map[row]);
	if (data->map[row][col] != prev_color)
		return ;
	if (row < 0 || row > data->nb_rows || col < 0 || col > data->big_line)
		return ;
	if (data->map[row][col] == 'L' || data->map[row][col] == '0' || data->map[row][col] == 'N')
		if (is_open(data, row, col))
			print_error("Map Invalid!! floor");
	char_change(data, row, col, new_color);
	if (col < data->big_line && col > 0)
		init_flood_fill(data, row, col + 1);
	if (row < data->nb_rows - 1)
		init_flood_fill(data, row + 1, col);	
	if (col < data->big_line && col > 0)
		init_flood_fill(data, row, col - 1);
	if (row > 0)
		init_flood_fill(data, row - 1, col);
	if (row - 1 > 0 && col - 1 > 0)
		init_flood_fill(data, row - 1, col -1);
	if (row < data->nb_rows - 1 && col > 0)
		init_flood_fill(data, row + 1, col - 1);
	if (row + 1 < data->nb_rows - 1 && col + 1 < data->big_line)
		init_flood_fill(data, row + 1, col + 1);
	if (row > 0 && col < data->big_line)
		init_flood_fill(data, row - 1, col + 1);	
}

int	is_open(t_data *data, int row, size_t col)
{
	if (data->map[0][col] == '0' || data->map[0][col] == 'L'
		|| data->map[data->nb_rows - 1][col] == '0'
		|| data->map[data->nb_rows - 1][col] == 'L')
		return (TRUE);
	if (is_space(data->map[row][col + 1]) || is_space(data->map[row][col - 1]) || is_space(data->map[row + 1][col]) || is_space(data->map[row - 1][col]))
		return (TRUE);
	return (FALSE);
}

int	is_space(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\0' || c == 'D')
		return (TRUE);
	return (FALSE);
}

void	char_change(t_data *data, int row, size_t col, char new_color)
{
	data->map[row][col] = new_color;
}

void	fill_structures_loop(t_data *data)
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
			else if (i > 6)
				fill_map(data, data->cub[i], i);
			else
				print_error("Map Invalid!! Please choose a map valid!!!");
		}
		i++;
	}
}

void	fill_map(t_data *data, char *line, int i)
{
	if (data->counter == 6 && data->control == 0)
	{
		data->counter = 0;
		data->nb_rows = data->nb_rows - i;
		if (data->nb_rows < 3)
			print_error("Map Invalid!! Please choose a map valid!!");
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
	exit(1);
}