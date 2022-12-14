/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:20:52 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:20:55 by jfrancis         ###   ########.fr       */
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

void	free_textures(t_data *data, int num_tex)
{
	int	i;

	i = 0;
	while (i < num_tex)
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
