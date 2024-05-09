/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:45:53 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/21 21:37:20 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n_bytes)
{
	unsigned char		*dest_d;
	unsigned const char	*src_s;
	size_t				i;

	dest_d = (unsigned char *)dest;
	src_s = (unsigned char *)src;
	if ((dest_d == NULL && src_s == NULL) || dest_d == src_s)
		return (dest);
	i = 0;
	while (i < n_bytes)
	{
		dest_d[i] = src_s[i];
		i++;
	}
	return (dest);
}
