/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:54:57 by coder             #+#    #+#             */
/*   Updated: 2022/11/30 23:57:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_invalid_file_texture(char *texture)
{
	char	**arr_split;
	int		file_map;

	arr_split = ft_split(texture, ' ');
	file_map = open(arr_split[1], O_RDONLY);
	if (ft_strncmp(arr_split[1], "./assets/", 9))
		return (is_invalid(arr_split, file_map));
	else if (!check_end_of_file(arr_split[1], "xpm"))
		return (is_invalid(arr_split, file_map));
	else if (file_map < 0)
		return (is_invalid(arr_split, file_map));
	return (!is_invalid(arr_split, file_map));
}

int	is_invalid(char **arr_split, int file_map)
{
	free_array(arr_split);
	close(file_map);
	return (TRUE);
}
