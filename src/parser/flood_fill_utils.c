/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:34:48 by coder             #+#    #+#             */
/*   Updated: 2022/11/30 23:44:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_open(t_data *data, int row, size_t col)
{
	if (data->map[0][col] == '0' || data->map[0][col] == 'L'
		|| data->map[row][0] == '0' || data->map[row][0] == 'L'
		|| data->map[data->nb_rows - 1][col] == '0'
		|| data->map[data->nb_rows - 1][col] == 'L')
		return (TRUE);
	if (is_space(data->map[row][col + 1]) || is_space(data->map[row][col - 1])
		|| is_space(data->map[row + 1][col])
			|| is_space(data->map[row - 1][col]))
		return (TRUE);
	return (FALSE);
}

int	is_space(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\0' || c == 'D'
		|| (c != '1' && c != '0' && c != 'L'
			&& ft_strchr(CHAR_PLAYER, c) == NULL))
		return (TRUE);
	return (FALSE);
}

void	char_change(t_data *data, int row, size_t col, char new_color)
{
	data->map[row][col] = new_color;
}
