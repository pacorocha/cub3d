/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:37:03 by coder             #+#    #+#             */
/*   Updated: 2022/12/07 20:57:28 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

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
