/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:25:33 by coder             #+#    #+#             */
/*   Updated: 2022/12/11 08:47:15 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_checker(t_data *data)
{
	checking_texture(data);
	checking_color(data);
	search_ocurrence_ground(data);
}

void	checking_texture(t_data *data)
{
	int	i;

	i = 0;
	while (data->directions[i] != NULL)
	{
		if (is_invalid_file_texture(data->directions[i]))
		{
			free_checker(data);
			if (i == 1)
				free(data->textures[i]);
			else
				free_textures(data, i);
			print_error("Error. Texture invalid!");
		}
		else
			map_texture(data, i, data->directions[i]);
		i++;
	}
}

void	map_texture(t_data *data, int i, char *texture)
{
	char	**arr_tex;
	char	*id;
	char	*path;

	arr_tex = ft_split(texture, ' ');
	id = ft_strdup(arr_tex[0]);
	path = ft_strdup(arr_tex[1]);
	data->textures[i] = (t_img *)malloc(sizeof(t_img));
	data->textures[i]->id = id;
	data->textures[i]->path = path;
	free_array(arr_tex);
}

void	checking_color(t_data *data)
{
	check_color(data, data->f_color);
	check_color(data, data->c_color);
	data->specs.f_rgb = get_color(data->f_color);
	data->specs.c_rgb = get_color(data->c_color);
}

void	check_color(t_data *data, char *color)
{
	char	**rgb;
	int		i;
	int		j;
	int		len_num;

	i = 0;
	if (ft_strchr(color, ','))
	{
		rgb = ft_split(color, ',');
		while (rgb[i] != NULL)
		{
			j = 0;
			len_num = ft_strlen(rgb[i]);
			while (j < len_num)
			{
				check_rgb_char(data, rgb, rgb[i][j], rgb[i]);
				j++;
			}
			i++;
		}
		verification_of_rgb_color(data, i, rgb);
	}
	else
		error_colors(data);
}
