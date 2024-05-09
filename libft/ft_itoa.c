/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:16:17 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/21 10:59:32 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	digits_len(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*digits_str;
	size_t		len;
	long int	nb;

	nb = n;
	len = digits_len(n);
	if (n < 0)
		nb = -nb;
	if (n == 0)
	{
		digits_str = ft_strdup("0");
		return (digits_str);
	}
	digits_str = malloc((len + 1) * sizeof(char));
	if (digits_str == NULL)
		return (NULL);
	digits_str[len] = '\0';
	while (len--)
	{
		digits_str[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		digits_str[0] = '-';
	return (digits_str);
}
