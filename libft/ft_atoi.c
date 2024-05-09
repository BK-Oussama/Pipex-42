/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:21:19 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/18 20:52:57 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	rslt;

	i = 0;
	sign = 1;
	rslt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ((str[i] != '\0' && str[i] >= '0' && str[i] <= '9'))
	{
		rslt = rslt * 10 + (str[i] - '0');
		if (rslt > 9223372036854775807 / 10 && sign == 1)
			return (-1);
		else if (rslt > 9223372036854775807 / 10 && sign == -1)
			return (0);
		i++;
	}
	return (rslt * sign);
}
