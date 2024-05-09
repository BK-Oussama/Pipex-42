/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:01:26 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/21 16:33:00 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (ft_strdup(""));
	j = ft_strlen(s);
	while (i + start < j && i < len)
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (0);
	j = 0;
	while (i > 0)
	{
		str[j++] = s[start++];
		i--;
	}
	str[j] = '\0';
	return (str);
}
