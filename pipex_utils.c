/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:35:15 by ouboukou          #+#    #+#             */
/*   Updated: 2024/05/14 16:35:50 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while ((s[i]))
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	check_child_exit_status(pid_t proc1, pid_t proc2)
{
	int	status;

	status = 0;
	waitpid(proc1, NULL, 0);
	waitpid(proc2, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	exit(0);
}
