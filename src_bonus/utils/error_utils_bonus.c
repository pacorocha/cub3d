/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:25:49 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:25:51 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	print_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	error_colors(t_data *data)
{
	free_checker(data);
	free_textures(data, NUM_TEX);
	print_error("Error. Color must have 3 comma separated values");
}

void	verification_of_rgb_color(t_data *data, int i, char **rgb)
{
	if (i != 3)
	{
		free_array(rgb);
		error_colors(data);
	}
	free_array(rgb);
}
