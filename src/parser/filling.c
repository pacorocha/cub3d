/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:19:04 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 22:37:49 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(t_data *data)
{
	if (data->argc != 2)
	{
		free_array(data->cub);
		print_error("Error. Add only one argument");
	}
	fill_structures_loop(data);
	if (data->map == NULL)
		free_minimun_lines_map(data);
	if (data->counter_flow > 5)
	{
		add_char_lines(data);
		if (data->num_player != 1)
		{
			free_checker(data);
			print_error("Error. Only one player is allowed!");
		}
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
		if (data->counter_flow <= 3)
		{
			if (data->cub[i][0] != '\0')
			{
				check_flags_directions(data, data->cub[i], data->counter_flow);
				fill_arr_textures(data, data->cub[i]);
			}
		}
		else if (data->counter_flow == 4 || data->counter_flow == 5)
		{
			if (data->cub[i][0] != '\0')
			{
				check_flags_colors(data, data->cub[i]);
				fill_arr_colors(data, data->cub[i]);
			}
		}
		else if (data->counter_flow > 5)
			get_map(data, i);
		i++;
	}
}

void	fill_arr_textures(t_data *data, char *line)
{
	if (data->counter_flow == 0)
	{
		data->directions = (char **)ft_calloc(5, sizeof(char *));
		data->directions[data->counter_flow] = line;
	}
	else
		data->directions[data->counter_flow] = line;
	if (data->counter_flow == 3)
		data->directions[data->counter_flow + 1] = NULL;
	data->counter_flow++;
}

void	fill_arr_colors(t_data *data, char *line)
{
	char	**str_splitted;

	str_splitted = ft_split(line, ' ');
	if (!ft_strncmp(line, "F ", 2) && data->control_color == 1)
		data->f_color = ft_strdup(str_splitted[1]);
	else if (!ft_strncmp(line, "C ", 2) && data->control == 1)
		data->c_color = ft_strdup(str_splitted[1]);
	else
	{
		free_array(data->cub);
		free(data->directions);
		if (data->c_color != NULL)
			free(data->c_color);
		if (data->f_color != NULL)
			free(data->f_color);
		free_array(str_splitted);
		print_error("Error, not init valid colors.");
	}
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
			free_minimun_lines_map(data);
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
