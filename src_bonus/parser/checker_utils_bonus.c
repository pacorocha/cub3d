/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:18:42 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 21:57:33 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	is_invalid_file_texture(char *texture)
{
	char	**arr_split;
	int		file_map;

	arr_split = ft_split(texture, ' ');
	file_map = open(arr_split[1], O_RDONLY);
	if (ft_strncmp(arr_split[1], "./assets/", 9))
		return (is_invalid(arr_split));
	else if (!check_end_of_file(arr_split[1], "xpm"))
		return (is_invalid(arr_split));
	else if (file_map < 0)
		return (is_invalid(arr_split));
	close(file_map);
	free_array(arr_split);
	return (FALSE);
}

int	is_invalid(char **arr_split)
{
	free_array(arr_split);
	return (TRUE);
}

void	check_rgb_char(t_data *data, char **rgb_arr, char rgb_char, char *rgb)
{
	if (rgb_char != '\0')
	{
		if (!ft_isdigit(rgb_char))
		{
			free_checker(data);
			free_textures(data, NUM_TEX);
			free_array(rgb_arr);
			print_error("Error, color not a number");
		}
		if (ft_atoi(rgb) < 0 || ft_atoi(rgb) > 255)
		{
			free_checker(data);
			free_textures(data, NUM_TEX);
			free_array(rgb_arr);
			print_error("Error, color > 255 or < 0 ");
		}
	}
}

void	get_map(t_data *data, int i)
{
	data->control = 0;
	verification_char_line(data, data->cub[i]);
	count_col(data, i);
	fill_map(data, data->cub[i], i);
}

void	verification_char_line(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] != '1' && line[i] != ' '
				&& line[i] != '\t' && line[i] != '0')
			&& !ft_strchr(CHAR_PLAYER, line[i]))
		{
			free_array(data->cub);
			free(data->directions);
			if (data->c_color != NULL)
				free(data->c_color);
			if (data->f_color != NULL)
				free(data->f_color);
			print_error("Error, not init valid colors.");
		}
		i++;
	}
}
