#include "../tasks.h"
// Copy from argv
char **ft_dup (char **argv, int argc, int *index)
{
    char **args = (char **)malloc (sizeof (char *) * argc);
    int i = 1;
    while (i < argc && argv && argv[i])
    {
        args[*index] = strdup(argv[i]);
        if (!args[*index])
            return NULL;
        i++;
        (*index)++;
    }
    args[*index] = NULL;
    return args;
}
