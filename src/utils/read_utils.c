/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:21:15 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:21:17 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_end_of_file(char *file, char *sufx)
{
	int	counter;

	counter = 0;
	while (file[counter + 1])
		counter++;
	while (counter >= 0 && file[counter] != '.')
		counter--;
	if (counter >= 0 && !ft_strcmp(file + counter + 1, sufx))
		return (1);
	return (0);
}
