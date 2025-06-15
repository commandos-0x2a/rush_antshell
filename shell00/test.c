#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// if (fork())
// 	{
// 		char *argv[] = {
// 			"grep",
// 			"A",
// 		};
// 		execve("/usr/bin/grep", argv, NULL);
// 		// perror("execve");
// 		// exit(1);
// 	}

int main()
{
	int fd = open("data.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	dup2(fd, 0);

	char buf[1024];
	ssize_t bytes = read(0, buf, sizeof(buf));
	write(1, buf, bytes);
	return (0);
}