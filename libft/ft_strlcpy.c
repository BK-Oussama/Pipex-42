/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:20:24 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/20 12:06:42 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	if (src && !dsize)
		return (ft_strlen(src));
	while (i < dsize - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < dsize)
	{
		dest[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
