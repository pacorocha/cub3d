/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:19:58 by coder             #+#    #+#             */
/*   Updated: 2022/12/09 21:04:14 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_flags_directions(t_data *data, char *line, int counter)
{
	if ((!ft_strncmp(line, "NO ", 3) && counter == 0)
		|| (!ft_strncmp(line, "SO ", 3) && counter == 1)
		|| (!ft_strncmp(line, "WE ", 3) && counter == 2)
		|| (!ft_strncmp(line, "EA ", 3) && counter == 3))
		return ;
	else
	{
		free_array(data->cub);
		if (counter > 0)
			free(data->directions);
		else if (counter > 1)
			free_array(data->directions);
		print_error("Error, not init valid directions");
	}
}

void	check_flags_colors(t_data *data, char *line, int counter)
{
	if ((!ft_strncmp(line, "F ", 2) && counter == 4)
		|| (!ft_strncmp(line, "C ", 2) && counter == 5))
		return ;
	else
	{
		free_array(data->cub);
		free(data->directions);
		if (counter == 5)
			free(data->f_color);
		print_error("Error, not init valid colors");
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
			j++;
		}
		i++;
	}
}
