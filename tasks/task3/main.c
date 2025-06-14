#include "../tasks.h"

int main (int ac, char **av)
{
    (void)av;
    if (ac != 1)
        return 1;
    while (1)
    {
        char *input = readline ("antshell$ ");
        if (!input)
            break ; 
        add_history(input);
        int pid = fork ();
        if (pid == 0)
        {
            int i = 0;
            char d = '"';
            char s = '\'';
            int  d_qouted = 0;
            int  s_qouted = 0;
            char **args;

            while (input[i])
            {
                if (strchr(input, d))
                    d_qouted = 1;
                else if (strchr (input, s))
                    s_qouted = 1;
                i++;
            }
            if (d_qouted)
                args = ft_split (input, '"');
            else if (s_qouted)
                args = ft_split (input, '\'');
            else
                args = ft_split (input, ' ');
            if (strcmp(args[0], "echo") == 0)
            {
                execve ("/usr/bin/echo", args, NULL);
                perror ("execve");
            }
            else
            {
                execve (args[0], args, NULL);
                perror (args[0]);
            }
            free (args);
            exit (1);
        }
        wait (NULL);
    } 
    return 0;
}

// int pid = fork ();
// if (pid == 0)
// {
//     int i = 1;
//     int j = 2;
//     char **args = (char **)malloc (sizeof (char *) * (ac - 1));
//     args[0] = "echo";
//     while (j < ac)
//     {
//         args[i] = av[j];
//         i++;
//         j++;
//     }
//     args[i] = NULL;
//     args[i] = NULL;
//     execve ("/usr/bin/echo", args, NULL);
//     perror ("execve");
//     free (args);
//     exit (1);
// }