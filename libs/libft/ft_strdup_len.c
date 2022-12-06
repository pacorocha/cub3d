/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:13:33 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/03 00:20:52 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_len(const char *s, size_t len_str)
{
	size_t	size;
	char	*dest;

	size = len_str + 1;
	dest = malloc(size);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, size);
	return (dest);
}