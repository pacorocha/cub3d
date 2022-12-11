/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:10:58 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 08:36:42 by jfrancis         ###   ########.fr       */
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
