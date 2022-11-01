/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:57:43 by jfrancis          #+#    #+#             */
/*   Updated: 2022/10/29 19:09:47 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_i;
	size_t	src_i;
	size_t	i;
	size_t	j;

	dest_i = ft_strlen(dest);
	src_i = ft_strlen(src);
	i = dest_i;
	j = 0;
	if (dest_i >= size)
		return (src_i + size);
	while (src[j] != '\0' && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (src_i + dest_i);
}
