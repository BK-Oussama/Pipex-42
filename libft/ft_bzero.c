/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:21:53 by ouboukou          #+#    #+#             */
/*   Updated: 2023/11/16 14:20:41 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n_bytes)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n_bytes)
	{
		*str = '\0';
		n_bytes--;
		str++;
	}
}
