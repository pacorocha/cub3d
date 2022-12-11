/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:18:27 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:18:31 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_flags_directions(t_data *data, char *line, int counter)
{
	if (!ft_strncmp(line, "NO ", 3)
		|| !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3)
		|| !ft_strncmp(line, "EA ", 3))
		return ;
	else
	{
		free_array(data->cub);
		if (counter > 0)
			free(data->directions);
		else if (counter > 1)
			free_array(data->directions);
		print_error("Error, not init valid directions.");
	}
}

void	check_flags_colors(t_data *data, char *line)
{
	if (!ft_strncmp(line, "F ", 2)
		|| !ft_strncmp(line, "C ", 2))
		return ;
	else
	{
		free_array(data->cub);
		free(data->directions);
		if (data->c_color != NULL)
			free(data->c_color);
		if (data->f_color != NULL)
			free(data->f_color);
		print_error("Error, not init valid colors.");
	}
}

void	add_char_lines(t_data *data)
{
	int		i;
	size_t	j;
	size_t	len_num;

	i = 0;
	len_num = data->big_line + 1;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (j < len_num)
		{
			if (ft_strlen(data->map[i]) <= len_num)
				ft_strlcat(data->map[i], "D", len_num);
			have_player(data, data->map[i][j]);
			j++;
		}
		i++;
	}
}

void	have_player(t_data *data, char c_current)
{
	if (ft_strchr(CHAR_PLAYER, c_current))
	{
		if (c_current != '\0')
			data->num_player++;
	}
}
