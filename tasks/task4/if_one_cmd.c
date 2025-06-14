#include "../tasks.h"

void if_one_cmd (char *av)
{
    int pid = fork ();
        if (pid == 0)
        {
             char **cmd = ft_split (av, ' ');
             execvp (cmd[0], cmd);
             perror ("execvp");
             free (cmd);
        }
}