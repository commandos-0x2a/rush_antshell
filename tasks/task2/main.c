#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	
	int id = fork();
	if (id == 0)
	{
        char *av []=
	{
		"grep",
		"A",
		NULL 
	};
        int fd = open("infile.txt", O_RDONLY);
        dup2(fd, 0);
        close(fd);
        int fd2 = open("outfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
        dup2(fd2, 1);
        close(fd2);
		execve("/usr/bin/grep", av, NULL);
		perror("execve");
		exit(1);
	}
    char *a []=
	{
		"echo",
		"AAAAAAA",
		NULL 
	};
	int id2 = fork();
	if (id2 == 0)
	{
        int fd3 = open("out2.txt", O_RDWR | O_CREAT | O_TRUNC , 0777);
        dup2(fd3, 1);
        close(fd3);
		execve("/usr/bin/echo", a, NULL);
		perror("execve");
		exit(1);
	}
	
	wait(NULL);
    wait(NULL);
	return (0);
}
