#include "../tasks.h"
void	free_2d(char **arr)
{
	int	i = 0;

	if (!arr)
		return;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int main(void)
{
    char *input;
	char ** cmd;
	int i ;
	int j ;
	int count;
	char **tok;
	int fd_in;
	int fd_out;
	int fd_app;

        while (1)
        {
            input = readline("minishell$ ");
            if (input == NULL)
                break;
            if (*input)
                add_history(input);
				tok = ft_split(input, ' ');
					count = 0;
						while (tok[count])
							count++;
						cmd = malloc(sizeof(char *) * (count + 1));
						if (!cmd)
							return (1);
				i = 0;
				j = 0;
				while(tok[i])
				{
					if (strcmp(tok[i], "<") == 0)
					{
							fd_in= open(tok[i + 1], O_RDONLY);
							//dup2(fd_in,0);
							//close(fd_in);
						i += 2;
					}
					else if (strcmp(tok[i], ">") == 0)
					{
						fd_out = open(tok[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
						//dup2(fd_out, 1);
						//close(fd_out);
						i += 2;
					}
					else if (strcmp(tok[i], ">>") == 0)
					{
						fd_app = open(tok[i + 1], O_RDWR | O_CREAT | O_APPEND, 0777);
						//dup2(fd_app, 1);
						//close(fd_app);
						i += 2;
					}
					else
					{		
						cmd[j++] = ft_strdup(tok[i++]);
					}
				}
				cmd[j] = NULL;
				int pid = fork();
				if (pid == 0)
				{
					if (fd_in > 0)
					{
						dup2(fd_in,0);
						close(fd_in);
					}
					if (fd_out > 0)
					{
						dup2(fd_out, 1);
						close(fd_out);
					}
					if (fd_app > 0)
					{
						dup2(fd_app, 1);
						close(fd_app);
					}
					execvp(cmd[0], cmd);
					perror("execvp");
					exit(1);
				}
				else
				{
					int status;
					waitpid(pid, &status, 0);
				}
            if (strcmp(input, "exit") == 0)
                break;
			free_2d(cmd);
			free_2d(tok);
			free(input); 
			}
			return (0);
}
























/*int main()
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
		"asmaa \n sma",
		NULL 
	};
	int id2 = fork();
	if (id2 == 0)
	{
        int fd3 = open("out2.txt", O_RDWR | O_CREAT , 0777);
        dup2(fd3, 1);
        close(fd3);
		execve("/usr/bin/echo", a, NULL);
		perror("execve");
		exit(1);
	}
	
	wait(NULL);
    wait(NULL);
	return (0);
}*/