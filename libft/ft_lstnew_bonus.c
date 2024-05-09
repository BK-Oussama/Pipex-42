/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:17:45 by ouboukou          #+#    #+#             */
/*   Updated: 2023/12/28 12:44:12 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rslt;

	rslt = (t_list *)malloc(sizeof(t_list));
	if (rslt == NULL)
		return (NULL);
	rslt->content = content;
	rslt->next = NULL;
	return (rslt);
}
