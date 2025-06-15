#include "antshell.h"

// int main(void)
// {
// 	while (1)
// 	{
// 		char *arr = readline("antshell>");
// 		if (!arr)
// 		{
// 			printf("\nexit\n");
// 			break;
// 		}
// 		add_history(arr);
// 		forking(arr);
// 		free(arr);
// 	}
// 	return 0;
// }

// #include "../tasks.h"

// int main(int ac, char **av)
// {
// 	(void)av;
// 	if (ac != 1)
// 		return 1;
// 	while (1)
// 	{
// 		char *input = readline("antshell$ ");
// 		if (!input)
// 			break;
// 		add_history(input);
// int pid = fork();
// if (pid == 0)
// {
// 	int i = 0;
// 	// char d = '"';
// 	// char s = '\'';
// 	// int  d_qouted = 0;
// 	// int  s_qouted = 0;
// 	char **args;

// 	while (input[i])
// 	{
// if (strchr(input, d))
//     d_qouted = 1;
// else if (strchr (input, s))
//     s_qouted = 1;
// i++;
// }
// if (d_qouted)
//     args = ft_split (input, '"');
// else if (s_qouted)
//     args = ft_split (input, '\'');
// else args = ft_split(input, ' ');
// if (strcmp(args[0], "echo") == 0)
// {
// 	execve("/usr/bin/echo", args, NULL);
// 	perror("execve");
// }
// else
// {
// 				execve(args[0], args, NULL);
// 				perror(args[0]);
// 			}
// 			free(args);
// 			exit(1);
// 		}
// 		wait(NULL);
// 	}
// 	return 0;
// }

void free_2d(char **arr)
{
	int i = 0;

	if (!arr)
		return;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
char **qoutes(char *input , char **tok)
{
	char d = '"';
	char s = '\'';
	int d_qouted = 0;
	int s_qouted = 0;

	if (strchr(input, d))
		d_qouted = 1;
	else if (strchr(input, s))
		s_qouted = 1;
	if (d_qouted)
		tok = ft_split(input, '"');
	else if (s_qouted)
		tok = ft_split(input, '\'');
	else
		tok = ft_split(input, ' ');
	return tok;
}

int main(void)
{
	char *input;
	char **cmd;
	int i;
	int j;
	int count;
	char **tok = NULL;
	int fd_in = -1;
	int fd_out = -1;
	int fd_app = -1;

	while (1)
	{
		input = readline("minishell$ ");
		if (input == NULL)
			break;
		if (*input)
			add_history(input);
		// tok = qoutes (input, tok);
		tok = ft_split(input, ' ');
		count = 0;
		while (tok[count])
			count++;
		cmd = malloc(sizeof(char *) * (count + 1));
		if (!cmd)
			return (1);
		i = 0;
		j = 0;
		while (tok[i])
		{
			if (strcmp(tok[i], "<") == 0)
			{
				fd_in = open(tok[i + 1], O_RDONLY);
				// dup2(fd_in,0);
				// close(fd_in);
				i += 2;
			}
			else if (strcmp(tok[i], ">") == 0)
			{
				fd_out = open(tok[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
				// dup2(fd_out, 1);
				// close(fd_out);
				i += 2;
			}
			else if (strcmp(tok[i], ">>") == 0)
			{
				fd_app = open(tok[i + 1], O_RDWR | O_CREAT | O_APPEND, 0777);
				// dup2(fd_app, 1);
				// close(fd_app);
				i += 2;
			}
			else
			{
				cmd[j++] = strdup(tok[i++]);
			}
		}
		cmd[j] = NULL;
		
		
		// printf ("cmd[0] '%s'\n", cmd[0]);
		int pid = fork();
		if (pid == 0)
		{
			if (fd_in > 0)
			{
				dup2(fd_in, 0);
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
			if (fd_app > 0)
			{
				close(fd_app);
				fd_app = -1;
			}
			if (fd_in > 0)
			{
				close(fd_in);
				fd_in = -1;
			}
			if (fd_out > 0)
			{
				close(fd_out);
				fd_out = -1;
			}
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
