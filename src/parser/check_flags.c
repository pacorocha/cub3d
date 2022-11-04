/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:19:58 by coder             #+#    #+#             */
/*   Updated: 2022/11/04 02:26:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_flags_cardinal_directions(char *line)
{
	if (!ft_strncmp(line, "NO ", 3) ||
	!ft_strncmp(line, "SO ", 3) ||
	!ft_strncmp(line, "WE ", 3) ||
	!ft_strncmp(line, "EA ", 3))
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

void	add_char_lines(t_data *data)
{
	int i;
	size_t j;
	size_t	len_num;
	
	i = 0;
	len_num = data->big_line + 1;
	while(data->map[i] != NULL)
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
