/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:46:44 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/21 10:45:35 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	len = ft_strlen(str);
	ptr = malloc((len + 1) * (sizeof(char)));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
