/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:39:58 by coder             #+#    #+#             */
/*   Updated: 2022/12/10 16:07:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while ((arr)[i])
	{
		free((arr)[i]);
		i++;
	}
	free(arr);
}

void	free_checker(t_data *data)
{
	free_array(data->cub);
	free_array(data->map);
	free(data->directions);
	free(data->f_color);
	free(data->c_color);
}

void	free_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_TEX)
	{
		free(data->textures[i]->id);
		free(data->textures[i]->path);
		free(data->textures[i]);
		i++;
	}
}

void	free_minimun_lines_map(t_data *data)
{
	free(data->f_color);
	free(data->c_color);
	free(data->directions);
	free_array(data->cub);
	print_error("Error. Invalid Map!!");
}
