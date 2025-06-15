#ifndef TASKS_H
#define TASKS_H

#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>

char	**ft_split(char const *str, char c);
size_t	count_words(char const *str, char delimeter);
void forking(char* line);

#endif