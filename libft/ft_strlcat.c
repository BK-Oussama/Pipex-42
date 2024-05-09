/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:08:31 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/31 21:28:30 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_length;
	unsigned int	src_length;

	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	j = ft_strlen(dest);
	if (dest_length >= size || size == 0)
		return (size + src_length);
	i = 0;
	while (i < (size - j - 1) && src[i] != '\0')
	{
		dest[dest_length] = src[i];
		i++;
		dest_length++;
	}
	dest[dest_length] = '\0';
	return (j + src_length);
}
