#include "../tasks.h"
// Copy from argv
char **ft_dup (char **args, char **argv, int argc, int *index)
{
    int i = 1;
    while (i < argc && argv && argv[i])
    {
        args[*index] = (char *) malloc (sizeof (char) * strlen (argv[i]) + 1);
        if (!args[*index])
            return NULL;
        strncpy(args[*index], argv[i], strlen (argv[i]));
        i++;
        (*index)++;
    }
    args[*index] = NULL;
    return args;
}
