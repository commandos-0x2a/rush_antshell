#include "antshell.h"

void forking(char* line)
{
    char **cmd;
    int pid;

    pid = fork ();
    if (pid == 0)
    {
        cmd = ft_split (line, ' ');
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
    

    int wstatus;
    wait(&wstatus);
    // waitpid(-1, &wstatus, 0);
}
