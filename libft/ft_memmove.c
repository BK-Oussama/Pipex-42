/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:13:41 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/23 22:44:59 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n_bytes)
{
	unsigned char		*dest_d;
	const unsigned char	*src_s;

	dest_d = (unsigned char *)dest;
	src_s = (const unsigned char *)src;
	if (dest_d == src_s || n_bytes == 0 || (dest_d == NULL && src_s == NULL))
		return (dest);
	if (dest_d < src_s || dest_d >= src_s + n_bytes)
	{
		ft_memcpy(dest_d, src_s, n_bytes);
	}
	else
	{
		dest_d = n_bytes + dest_d;
		src_s = n_bytes + src_s;
		while (n_bytes)
		{
			dest_d--;
			src_s--;
			*dest_d = *src_s;
			n_bytes--;
		}
	}
	return (dest);
}
