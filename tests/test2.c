#include <stdio.h>

int main(int argc, char ** argv)
{
	int i;
	printf("argc: %d\n", argc);
	i = 0;
	while (i < argc)
	{
		printf("argv[%i]: %s\n", i, argv[i]);
		i++;
	}
	return (0);
}