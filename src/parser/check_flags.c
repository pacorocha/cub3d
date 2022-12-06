/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:19:58 by coder             #+#    #+#             */
/*   Updated: 2022/12/06 01:15:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_flags_cardinal_directions(char *line, int counter)
{
	if ((!ft_strncmp(line, "NO ", 3) && counter == 0)
		|| (!ft_strncmp(line, "SO ", 3) && counter == 1)
		|| (!ft_strncmp(line, "WE ", 3) && counter == 2)
		|| (!ft_strncmp(line, "EA ", 3) && counter == 3))
		return (1);
	return (0);
}

int	check_flags_colors(char *line)
{
	if (!ft_strncmp(line, "F ", 2)
		|| !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

char	*add_char_lines(t_data *data, char *line)
{
	int		i;
	size_t	len_num;

	i = 0;
	len_num = data->big_line;

	while (line[i] != '\0')
	{
		if (ft_strlen(line) <= len_num)
			ft_strlcat(line, "D", len_num - 1);
		i++;
	}

	return (ft_strdup_len(line, data->big_line));
}
