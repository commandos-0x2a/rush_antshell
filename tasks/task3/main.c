#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int ac, char **av)
{
    int pid = fork ();
    if (pid == 0)
    {
        int i = 1;
        int j = 2;
        char **args = (char **)malloc (sizeof (char *) * (ac - 1));
        args[0] = "echo";
        while (j < ac - 1)
        {
            args[i] = av[j];
            i++;
            j++;
        }
        args[i] = NULL;
        execve ("/usr/bin/echo", args, NULL);
        perror ("execve");
        free (args);
        exit (1);
    }
    wait (NULL);
    return 0;
}