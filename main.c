#include "antshell.h"

int main (void)
{
    while (1)
	{
		char* arr = readline("antshell>");
		if (!arr) {
			printf("\nexit\n");
			break;
		}
		add_history(arr);
        forking (arr);
        free (arr);
	}
    return 0;
}