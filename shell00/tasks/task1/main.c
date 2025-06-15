#include "../tasks.h"

int main (int argc, char **argv)
{
    char **args;
    int index = 0;

    args = ft_dup (argv, argc, &index);

    forking (argc, args);
    free_all (args, argc);
    return 0;
}