/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:19:23 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 22:58:33 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_open(t_data *data, int row, size_t col)
{
	if (data->map[0][col] == '0' || data->map[0][col] == 'L'
		|| ft_strchr(CHAR_PLAYER, data->map[0][col])
		|| data->map[row][0] == '0' || data->map[row][0] == 'L'
		|| ft_strchr(CHAR_PLAYER, data->map[row][0])
		|| data->map[data->counter_map][col] == '0'
		|| ft_strchr(CHAR_PLAYER, data->map[data->counter_map][col])
		|| data->map[data->counter_map][col] == 'L')
		if (data->map[0][col] != '\0'
			|| data->map[row][0] != '\0'
			|| data->map[data->counter_map][col] != '\0')
			return (TRUE);
	if (is_space(data->map[row][col - 1]))
		return (TRUE);
	if (is_space(data->map[row][col + 1]))
		return (TRUE);
	if (is_space(data->map[row + 1][col]))
		return (TRUE);
	if (is_space(data->map[row - 1][col]))
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

void	check_dup_textures(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < NUM_TEX)
	{
		j = i + 1;
		while (j < NUM_TEX)
		{
			if (ft_strcmp(data->textures[i]->id, data->textures[j]->id) == 0)
			{
				free_checker(data);
				free_textures(data, NUM_TEX);
				print_error("Error: invalid textures.");
			}
			j++;
		}
		i++;
	}
}
