/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:29:00 by coder             #+#    #+#             */
/*   Updated: 2022/11/09 20:07:02 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	search_ocurrence_ground(t_data *data)
{
	int i;
	size_t j;
	size_t len_col;

	i = 0;
	data->control = 0;
	while(i < data->nb_rows - 1)
	{
		j = 0;
		len_col = ft_strlen(data->map[i]);
		while(j < len_col)
		{
			if (data->map[i][j] == '0')
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
	if (data->map[row][col] != prev_color)
		return ;
	if (row < 0 || row > data->nb_rows || (int)col < 0 || col > data->big_line)
		return ;
	if (data->map[row][col] == 'L' || data->map[row][col] == '0' || data->map[row][col] == 'N'
		|| data->map[row][col] != '1')
		if (is_open(data, row, col))
			print_error("Error, open map");
	char_change(data, row, col, new_color);
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

int	is_open(t_data *data, int row, size_t col)
{
	if (data->map[0][col] == '0' || data->map[0][col] == 'L'
		|| data->map[row][0] == '0' || data->map[row][0] == 'L'
		|| data->map[data->nb_rows - 1][col] == '0'
		|| data->map[data->nb_rows - 1][col] == 'L')
		return (TRUE);
	if (is_space(data->map[row][col + 1]) || is_space(data->map[row][col - 1]) || is_space(data->map[row + 1][col]) || is_space(data->map[row - 1][col]))
		return (TRUE);
	return (FALSE);
}

int	is_space(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\0' || c == 'D' || (c != '1' && c != '0' && c != 'L' && c != 'N'))
		return (TRUE);
	return (FALSE);
}

void	char_change(t_data *data, int row, size_t col, char new_color)
{
	data->map[row][col] = new_color;
}
