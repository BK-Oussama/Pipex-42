/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:21:50 by ouboukou          #+#    #+#             */
/*   Updated: 2024/05/12 12:30:12 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void   check_cmd_access(char *paths[], char *cmd, char **args)
{
    int     i;
    char    *c;
    i = 0;
    while (paths[i])
    {
        c = ft_strjoin(paths[i], "/");
        c = ft_strjoin(c, cmd);            
            if(access(c, F_OK | X_OK) == 0)
                execve(c, args, NULL);
    i++;
    }
}

static void retrive_paths(char **env, char *argv)
{
    int i;
    char **paths;
    char **cmd_args;

    i = 0;
    while (!ft_strnstr(env[i], "PATH", 4))
        i++;

    paths = ft_split(env[i] + 5, ':');
    cmd_args = ft_split(argv, ' ');
    check_cmd_access(paths, cmd_args[0], cmd_args);

}

static void first_child(char **argv, char **env, int *fd)
{
    int infile;
    infile = open(argv[1], O_RDONLY, 0644);
    if (infile < 0)
    {
        perror("fd infile error");
        exit(EXIT_FAILURE);
    }
    
    if (dup2(infile, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
    {
        perror("Duplication failed");
        exit(EXIT_FAILURE);
    }
    close(infile);
    close(fd[0]);
    close(fd[1]);
    retrive_paths(env, argv[2]);
}

static void     second_child(char **argv, char **env, int *fd)
{
    int outfile;
    outfile = open(argv[4],  O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (outfile < 0)
        perror("fd outfile error");
    if( dup2(fd[0], STDIN_FILENO) == -1 || dup2(outfile, STDOUT_FILENO) == -1) 
    {
        perror("Duplication failed");
        exit(EXIT_FAILURE);
    }
    close(outfile);
    close(fd[0]);
    close(fd[1]);
    retrive_paths(env, argv[3]);

}
int main(int argc, char *argv[], char *env[])
{

    if (argc != 5)
    {
        printf("please enter valid cmd and files");
        exit(EXIT_FAILURE);        
    }
    
    int     pipe_fd[2];
    pid_t   child_01;
    pid_t   child_02; 
        
    if (pipe(pipe_fd) == -1)
    {
        perror ("Pipe creation failed");
        exit(EXIT_FAILURE);
    }
    
    child_01 = fork();
    if (child_01 < 0)
    {
        perror("First child fork error!");
        return (EXIT_FAILURE);
    }
    else if (child_01 == 0)
    {      
        first_child(argv, env, pipe_fd);
        exit(EXIT_SUCCESS);
    }
    
    child_02 = fork();
    if (child_02 < 0)
    {
        perror("second child fork error!");
        return(EXIT_FAILURE);
    }
    else if (0 == child_02)
    {
        second_child(argv, env, pipe_fd);
        exit(EXIT_SUCCESS);
    }
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    waitpid(child_01, NULL, 0);
    waitpid(child_02, NULL, 0);

    return (EXIT_SUCCESS);
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
        child_01(f1, cmd1);
    child2 = fork();
    if (child2 < 0)
         return (perror("Fork: "));
    if (child2 == 0)
        child_02(f2, cmd2);
    close(end[0]);         // this is the parent
    close(end[1]);         // doing nothing
    waitpid(child1, &status, 0);  // supervising the children
    waitpid(child2, &status, 0);  // while they finish their tasks
}
*/
