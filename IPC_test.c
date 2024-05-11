/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IPC_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 08:16:52 by ouboukou          #+#    #+#             */
/*   Updated: 2024/05/11 19:38:46 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
    These values are always used for stdin , stdout, and stderr:
    - 0: stdin      ==> Used for reading input 
    - 1: stdout     ==> Used for writing output
    - 2: stderr
*/

/*
    in the bellow code i did found it difcult to knew wich block of code the child and the parent will excute,
    and then i did realize that the child will excute the else if (pid == 00) and the return success,
    the parent process wil excute the else block and then exit with success. 
*/
int main()
{
    int pid;
    int pfd[2];

    pipe(pfd);
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);     
        write(1, "This message from child to pop!", 31);
        exit(EXIT_SUCCESS);
    }
    else
    {
        close(pfd[1]);
        dup2(pfd[0], 0);
        close (pfd[0]);
        char str[31];
        read(0, str, 31);
        printf("Parent received:\t%s\n%d", str, getpid());
        wait (NULL);
    }
    return (EXIT_SUCCESS);
}

// #include <unistd.h>
// #include <stdio.h>

// int main()
// {
//  int  pfd[2];
//  char str[20];

//  pipe(pfd);
//  write(pfd[1], "hello", 5);
//  read(pfd[0], str, 2);
//  str[2] = '\0';
//  printf("%s\n",str);
// }


// void forkexample()
// {
// 	int x = 1;
// 	pid_t p = fork();
// 	if(p<0){
// 	perror("fork fail");
// 	exit(1);
// 	}
// 	else if (p == 0)
// 		printf("Child has x = %d\n", ++x);
// 	else
//     {
//         wait(NULL);
// 		printf("Parent has x = %d\n", --x);
//     }
// }
// int main()
// {
// 	forkexample();
// 	return 0;
// }

// void    callexecve()
// {
//  char *const args[] = { "ls", NULL };
//  char *const envp[] = { NULL };
 
//  execve("/usr/bin/ls", args, envp);
//  perror("execve");
//     exit(EXIT_FAILURE); // Make sure to exit the child process if execve fails 
// }

// int main(void)
// {
//  pid_t pid;
 
//  printf("Hi I am the main process. My PID is :%d\n", getpid());
//  pid = fork();
//  if (pid == -1)
//   printf("Error while forking\n");
//  else if (pid == 0)
//  {
//   printf("I am the child. But now a new parent. My PID is :%d --- My child's PID is %d\n", getpid(), pid);
//   callexecve();
//  }
//  else if (pid > 1)
//  {
//   printf("I am the parent. My PID is :%d --- My child's PID is %d\n", getpid(), pid);
//   waitpid(pid, NULL, 0); 
//   printf("Got back the control?\n");
//  }
// }


// void forkexample() {
//     pid_t p;
//     p = fork();
//     if (p < 0) {
//         perror("fork failed");
//         exit(1);
//     } else if (p == 0) {
//         printf("Hello from Child!\n");
//     } else {
//         // Parent process
//         int status;
//         // Wait for the child process to terminate
//         waitpid(p, &status, 0);
//         printf("Hello from Parent!\n");
//     }
// }

// int main() {
//     forkexample();
//     return 0;
// }





// int main()
// {
 
//     // make two process which run same
//     // program after this instruction
//     pid_t p = fork();
//     if(p<0){
//       perror("fork fail");
//       exit(1);
//     }
//     else if (0 == p)
//     {
//         printf("this excuted from child process (pid) = %d \n", getpid());
//     }
    
//     printf("Hello world!, process_id(pid) = %d \n",getpid());
//     return 0;
// }



// int main() {
//     int pid1;
//     int pid2;
    
//     pid1 = fork();
//     if (pid1 < 0) {
//         perror("fork failed");
//         exit(EXIT_FAILURE);
//     } else if (pid1 == 0) {
//         // Child process 1
//         printf("Yes, I'm child 1, pid: %d\n", getpid());
//     } else {
//         // Parent process
//         pid2 = fork();
//         if (pid2 < 0) {
//             perror("fork failed");
//             exit(EXIT_FAILURE);
//         } else if (pid2 == 0) {
//             // Child process 2
//             printf("Yes, I'm child 2, pid: %d\n", getpid());
//         } else {
//             // Parent process
//             printf("I'm the parent process, pid: %d\n", getpid());
//         }
//     }

//     return 0;
// }


// #include "pipex.h"

// int main()
// {

//     int pid1;
//     int pid2;
    
//     pid1 = fork();
//     if (0 == pid1)
//         printf("Yes, im child 1 %d\n", pid1);
    
//     else if (pid1 < 0)
//     {
//         printf("fork faild");
//     }
//     pid2 = fork();
//     if (0 == pid2)
//     {
//         printf("child 2 is excuting%d\n", pid2);
//     }
// }
