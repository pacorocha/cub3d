/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:38:56 by coder             #+#    #+#             */
/*   Updated: 2022/12/09 02:06:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	error_structures(t_data *data)
{
	free_array(data->cub);
	free(data->directions);
	free(data->f_color);
	free(data->c_color);
	print_error("Error, not init valid directions or colors");				
}
