/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:42:33 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/18 19:47:15 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int arg)
{
	size_t	len;

	len = ft_strlen(s);
	while (len)
	{
		if (*(s + len) == (char)arg)
			return ((char *)(s + len));
		len--;
	}
	if (*s == (char)arg)
		return ((char *)(s));
	return (NULL);
}
