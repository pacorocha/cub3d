/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:39:58 by coder             #+#    #+#             */
/*   Updated: 2022/12/07 20:57:13 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

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
