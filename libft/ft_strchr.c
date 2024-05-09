/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:16:00 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/06 10:42:20 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int arg)
{
	while (*s && *s != (char)arg)
	{
		s++;
		if (*s == (char)arg)
		{
			return ((char *)s);
		}
	}
	if (*s == (char)arg)
	{
		return ((char *)s);
	}
	return (NULL);
}
