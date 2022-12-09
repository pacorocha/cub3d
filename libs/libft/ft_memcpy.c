/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:59:54 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/08 23:59:09 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;

	c_dest = (char *)dest;
	c_src = (char *)src;
	
	if ((c_dest != NULL) || (c_src != NULL))
	{
		while (n--)
		{
			*(c_dest++) = *(c_src++);
		}
		
	}
	return (dest);
}
