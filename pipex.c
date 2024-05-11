/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:21:50 by ouboukou          #+#    #+#             */
/*   Updated: 2024/05/11 21:38:17 by ouboukou         ###   ########.fr       */
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
    int     infile;
    int     outfile;
    pid_t   first_child;
    pid_t   second_child;

    infile = open(argv[1], O_RDONLY);
    outfile = open(argv[4], O_CREAT | O_TRUNC, 0644); /* check if O_trunc is the disred  flag or O_append*/
    if (infile < 0 || outfile < 0)
        return; // add the write behvouir here!
    if (argc != 2)
        return 0;
    retrive_paths(env, argv[1]);
    return 0;
}

/*
void    pipex(int f1, int f2, char *cmd1, char *cmd 2)
{
    int   end[2];
    int   status;
    pid_t child1;
    pid_t child2;
    pipe(end);
    child1 = fork();
    if (child1 < 0)
         return (perror("Fork: "));
    if (child1 == 0)
        child_one(f1, cmd1);
    child2 = fork();
    if (child2 < 0)
         return (perror("Fork: "));
    if (child2 == 0)
        child_two(f2, cmd2);
    close(end[0]);         // this is the parent
    close(end[1]);         // doing nothing
    waitpid(child1, &status, 0);  // supervising the children
    waitpid(child2, &status, 0);  // while they finish their tasks
}
*/
