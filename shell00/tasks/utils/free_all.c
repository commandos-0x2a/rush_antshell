#include "../tasks.h"
void free_all (char **args, int argc)
{
    int i = 0;
    while (i < argc - 1)
    {
        free (args[i]);
        i++;
    }
    free (args);
}