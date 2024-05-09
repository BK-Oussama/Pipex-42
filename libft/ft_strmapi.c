/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:29:42 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/08 18:12:30 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*rslt;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	rslt = malloc((len + 1) * sizeof(char));
	if (rslt == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rslt[i] = f(i, s[i]);
		i++;
	}
	rslt[len] = '\0';
	return (rslt);
}
