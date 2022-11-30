/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:14:30 by coder             #+#    #+#             */
/*   Updated: 2022/11/30 23:44:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(t_data *data)
{
	if (data->argc != 2)
		print_error("Error, args");
	fill_structures_loop(data);
	add_char_lines(data);
	map_checker(data);
}

void	fill_structures_loop(t_data *data)
{
	int	i;

	i = 0;
	while (data->cub[i] != NULL)
	{
		if (data->cub[i][0] != '\0')
		{
			if (check_flags_cardinal_directions(data->cub[i], data->counter))
				fill_arr_textures(data, data->cub[i], i);
			else if (check_flags_colors(data->cub[i]) && data->counter >= 3)
				fill_arr_colors(data, data->cub[i]);
			else if (i >= 6)
			{
				count_col(data, i);
				fill_map(data, data->cub[i], i);
			}
			else
				print_error("Error, not init valid directions or colors");
		}
		i++;
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
	data->counter++;
}

void	fill_arr_colors(t_data *data, char *line)
{
	char	**str_splitted;

	str_splitted = ft_split(line, ' ');
	if (!ft_strncmp(line, "F ", 2))
		data->f_color = ft_strdup(str_splitted[1]);
	else
		data->c_color = ft_strdup(str_splitted[1]);
	free(str_splitted);
	data->counter++;
}

void	fill_map(t_data *data, char *line, int i)
{
	if (data->counter == 6 && data->control == 0)
	{
		data->counter = 0;
		data->nb_rows = data->nb_rows - i;
		if (data->nb_rows < 3)
			print_error("Error");
		data->map = (char **)ft_calloc(data->nb_rows + 1, sizeof(char *));
		data->map[data->counter] = ft_strdup_len(line, data->big_line);
	}
	else
	{
		data->counter++;
		data->map[data->counter] = ft_strdup_len(line, data->big_line);
		data->control = 1;
	}
	if (data->counter == data->nb_rows - 1)
	{
		data->map[data->counter + 1] = NULL;
		data->control = 1;
	}
}
