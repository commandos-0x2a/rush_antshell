#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("data.txt", O_RDONLY);
	int fd2 = open("write.txt", O_RDWR | O_CREAT, 0777);
	dup2(fd, 0);
	dup2(fd2, 1);

	char *av []=
	{
		"grep",
		"4",
		NULL 
	};
	int id = fork();
	if (id == 0)
	{
		execve("/usr/bin/grep", av, NULL);
		perror("execve");
		exit(1);
	}
	
	wait(NULL);
	close(fd);
	close(fd2);
	return (0);
}