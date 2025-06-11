#include "../tasks.h"

int main (int argc, char **argv)
{
    char **args = (char **)malloc (sizeof (char *) * argc);
    if (!args)
        return 1;
    int index = 0;
    args = ft_dup (args, argv, argc, &index);

    forking (argc, args);
   
    free_all (args, argc);
    return 0;
}