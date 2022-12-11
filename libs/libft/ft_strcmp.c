/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 01:09:13 by Dmonteir          #+#    #+#             */
/*   Updated: 2022/12/11 08:35:47 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int	counter;

	counter = 0;
	while ((unsigned char)str1[counter] == \
	(unsigned char)str2[counter] && str1[counter])
		counter++;
	return ((unsigned char)str1[counter] - (unsigned char)str2[counter]);
}
