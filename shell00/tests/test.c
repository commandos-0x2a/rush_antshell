#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void print_status (int wstatus)
{
		if (WIFEXITED(wstatus))
	{
		printf("Exited with %d\n",WEXITSTATUS(wstatus));
	}
	if (WIFSIGNALED(wstatus))
	{
		printf("Signaled by %d\n", WTERMSIG(wstatus));
	}

}

int main()
{
	char *argv[] = {
		"ls",
		NULL
	};
	int pid = fork();
	if (pid == 0)
	{
		// execve("/bin/ls", argv, NULL);
		// perror("execve");
		exit(1);
	}
	int pid2 = fork();
	if (pid2 == 0)
	{
		// execve("/bin/ls", argv, NULL);
		// perror ("execve2");
		sleep (5);
		exit(2);
	}
	printf("test\n");
	kill(pid2, SIGKILL);
	int wstatus;
	waitpid(pid, &wstatus, 0);
	print_status (wstatus);
	waitpid(pid2, &wstatus, 0);
	print_status (wstatus);
}