#include "../tasks.h"
void forking(int argc, char **args)
{
    int i = 0;
    int pid;
    while (i < argc)
       {
           pid = fork ();
           if (pid == 0)
           {
               char **cmd = (char **) malloc (sizeof (char) * (count_words (args[i], ' ')) + 1);
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
           else
           {
               int wstatus;
               waitpid (pid, &wstatus, 0);
           }
           i++;
       }
}
