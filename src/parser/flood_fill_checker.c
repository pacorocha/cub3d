/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:19:13 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:19:15 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	search_ocurrence_ground(t_data *data)
{
	int		i;
	size_t	j;
	size_t	len_col;

	i = 0;
	data->control = 0;
	while (i < data->counter_map)
	{
		j = 0;
		len_col = ft_strlen(data->map[i]);
		while (j < len_col)
		{
			if (data->map[i][j] == '0'
				|| ft_strchr(CHAR_PLAYER, data->map[i][j]))
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
	flood_fill(data, i, j);
}

void	flood_fill(t_data *data, int row, size_t col)
{
	char	new_color;
	char	prev_color;

	new_color = 'L';
	prev_color = '0';
	data->big_line = ft_strlen(data->map[row]);
	if (data->map[row][col] == 'L'
		|| ft_strchr(CHAR_PLAYER, data->map[row][col])
		|| data->map[row][col] == '0'
		|| (data->map[row][col] != 'D'
		&& data->map[row][col] != '1'))
	{
		if (is_open(data, row, col))
		{
			free_checker(data);
			free_textures(data, NUM_TEX);
			print_error("Error. Invalid Map!!");
		}
	}
	if (data->map[row][col] != prev_color)
		return ;
	if (row < 0 || row > data->nb_rows || (int)col < 0 || col > data->big_line)
		return ;
	char_change(data, row, col, new_color);
	verification_sides_of_char(data, row, col);
}

void	verification_sides_of_char(t_data *data, int row, size_t col)
{
	if (col < data->big_line && col > 0)
		flood_fill(data, row, col + 1);
	if (row < data->nb_rows - 1)
		flood_fill(data, row + 1, col);
	if (col < data->big_line && col > 0)
		flood_fill(data, row, col - 1);
	if (row > 0)
		flood_fill(data, row - 1, col);
	if (row - 1 > 0 && col - 1 > 0)
		flood_fill(data, row - 1, col -1);
	if (row < data->nb_rows - 1 && col > 0)
		flood_fill(data, row + 1, col - 1);
	if (row + 1 < data->nb_rows - 1 && col + 1 < data->big_line)
		flood_fill(data, row + 1, col + 1);
	if (row > 0 && col < data->big_line)
		flood_fill(data, row - 1, col + 1);
}
