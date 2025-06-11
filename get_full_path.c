/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:33:51 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/06/11 04:55:52 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

static int	search_command_path(char *full_path, char *cmd)
{
	char	*path_env;
	char	*path;

	path_env = getenv("PATH");
	if (!path_env)
		return (-1);
	path = strtok(path_env, ":");
	while (path)
	{
		if (snprintf(full_path, PATH_MAX, "%s/%s", path, cmd) < PATH_MAX
			&& access(full_path, X_OK) == 0)
		{
			free(path_env);
			return (0);
		}
		path = strtok(NULL, ":");
	}
	free(path_env);
	return (1);
}

char	*get_full_path(char *cmd)
{
	int	err;
	char	*full_path;

	full_path = malloc(PATH_MAX + 1);
	if (!full_path)
		return (NULL);
	if (strlcpy(full_path, cmd, PATH_MAX) >= PATH_MAX)
	{
		free(full_path);
		errno = ENAMETOOLONG;
		return (NULL);
	}
	if (strncmp(cmd, "/", 1) == 0
		|| strncmp(cmd, "./", 2) == 0
		|| strncmp(cmd, "../", 3) == 0)
		return (full_path);
	err = search_command_path(full_path, cmd);
	if (err == -1)
	{
		free(full_path);
		return (NULL);
	}
	if (err == 1)
	{
		free(full_path);
		fprintf(stderr, "antshell: %s: command not found\n", cmd);
		return (NULL);
	}
	return (full_path);
}
