/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:09:01 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/23 22:45:27 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int value, size_t n_byt)
{
	unsigned char	*str;

	value = (unsigned char)value;
	str = (unsigned char *)s;
	if (n_byt == 0)
		return (s);
	while (n_byt)
	{
		*str = value;
		n_byt--;
		str++;
	}
	return (s);
}
