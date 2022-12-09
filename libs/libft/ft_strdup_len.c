/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:13:33 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/08 23:59:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup_len(const char *s, size_t len_str)
{
	size_t	size;
	char	*dest;

	size = len_str + 1;
	dest = ft_calloc(size, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, ft_strlen(s));
	return (dest);
}