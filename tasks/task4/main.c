#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../tasks.h"
//./antshell "ls" "cat -e"

int main (int ac, char **av)
{
    if (ac < 2)
        return 1;
    if (ac == 2 && av[1][0] != '\0')
        if_one_cmd (av[1]);
    int fd[2];
    if (pipe(fd) == -1)
        return 1;
    int pid = fork();
    // write fd [1]
    // close fd [0]
    if (pid == 0)
    {
        close (fd[0]);
        dup2 (fd[1], 1);
        if_one_cmd (av[1]);
        close (fd[1]);
        
    }
    else
    {
        close (fd[1]);
        dup2 (fd[0], 0);
        if_one_cmd (av[2]);
        close (fd[2]);
    }
    wait (NULL);
}