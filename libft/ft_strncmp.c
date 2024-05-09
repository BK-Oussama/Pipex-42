/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:24:41 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/21 18:00:48 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]
		&& (n - 1) > i)
	{
		i++;
	}
	if (((unsigned char *) s1)[i] < ((unsigned char *)s2)[i])
		return (-1);
	else if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
		return (1);
	return (0);
}
