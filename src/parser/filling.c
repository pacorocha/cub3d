/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:14:30 by coder             #+#    #+#             */
/*   Updated: 2022/12/09 22:04:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(t_data *data)
{
	if (data->argc != 2)
		print_error("Error. Add only one argument");
	fill_structures_loop(data);
	if (data->counter_flow > 5)
	{
		add_char_lines(data);
		map_checker(data);
	}
	else
	{
		free_array(data->cub);
		print_error("Error. Invalid File");
	}	
}

void	fill_structures_loop(t_data *data)
{
	int	i;

	i = 0;
	while (data->cub[i] != NULL)
	{
		if (data->cub[i][0] != '\0')
		{
			if (data->counter_flow <= 3)
			{
				check_flags_directions(data, data->cub[i], data->counter_flow);
				fill_arr_textures(data, data->cub[i], i);
			}
			else if (data->counter_flow == 4 || data->counter_flow == 5)
			{
				check_flags_colors(data, data->cub[i], data->counter_flow);
				fill_arr_colors(data, data->cub[i]);
			}	
			else if (data->counter_flow > 5)
			{
				count_col(data, i);
				fill_map(data, data->cub[i], i);
			}
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
	data->counter_flow++;
}

void	fill_arr_colors(t_data *data, char *line)
{
	char	**str_splitted;

	str_splitted = ft_split(line, ' ');
	if (!ft_strncmp(line, "F ", 2))
		data->f_color = ft_strdup(str_splitted[1]);
	else
		data->c_color = ft_strdup(str_splitted[1]);
	free_array(str_splitted);
	data->counter_flow++;
}

void	fill_map(t_data *data, char *line, int i)
{
	if (data->counter_flow == 6 && data->control == 0)
	{
		data->counter_map = 0;
		data->nb_rows = data->nb_rows - i;
		if (data->nb_rows < 3)
			print_error("Error");
		data->map = (char **)ft_calloc(data->nb_rows + 1, sizeof(char *));
		data->map[data->counter_map] = ft_strdup_len(line, data->big_line);
	}
	else
	{
		data->counter_map++;
		data->map[data->counter_map] = ft_strdup_len(line, data->big_line);
		data->control = 1;
	}
	if (data->counter_map == data->nb_rows - 1)
	{
		data->map[data->counter_map + 1] = NULL;
		data->control = 1;
	}
	data->counter_flow++;
}
