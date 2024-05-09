/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:21:50 by ouboukou          #+#    #+#             */
/*   Updated: 2024/05/08 19:23:55 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void   check_cmd_access(char *paths[], char *cmd, char **args)
{
    int     i;
    char    *c;
    i = 0;
    while (paths[i])
    {
        c = ft_strjoin(paths[i], "/");
        c = ft_strjoin(c, cmd);            
            if(access(c, F_OK | X_OK) == 0)
            {
                printf("[%d]\tthe path: %s\n", i, paths[i]);
                execve(c, args, NULL);
            }
            else
                free (c);
        i++;
    }
}

char **retrive_paths(char **env, char *argv)
{
    int i;
    char **paths;
    char **cmd_args;

    i = 0;
    while (!ft_strnstr(env[i], "PATH", 4))
        i++;

    paths = ft_split(env[i] + 5, ':');
    cmd_args = ft_split(argv, ' ');
    i=0;
    while(cmd_args[i])
    {
        printf("[%d]\t%s\n", i, cmd_args[i]);
        i++;
    }
    check_cmd_access(paths, cmd_args[0], cmd_args);
    return (paths);

}

int main(int argc, char *argv[], char *env[])
{
    // char *cmd1 = argv[2];
    // char *cmd2 = argv[3];
    // char *args = "";
    if (argc != 2)
        return 0;
    retrive_paths(env, argv[1]);
    return 0;
}
