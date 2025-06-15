#include "../tasks.h"
#include <stdio.h>

void forking(int argc, char **args)
{
    int i = 0;
    char **cmd;
    int pid;

    while (i < argc - 1)
    {
        pid = fork ();
        if (pid == 0)
        {
            cmd = ft_split (args[i], ' ');
            // int j = 0;
            // int words = count_words (args[i], ' ');
            execvp (cmd[0], cmd);
            perror ("execvp");

            int j = 0;
            while (cmd[j])
            {
                free(cmd[j]);
                j++;
            }
            free(cmd);
            exit (1);
        }
        i++;
    }

    int wstatus;
    i = 0;
    while (i < argc - 1)
    {
        wait(&wstatus);
        i++;
    }
    // waitpid(-1, &wstatus, 0);
}
