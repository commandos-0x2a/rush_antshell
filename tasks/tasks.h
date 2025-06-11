#ifndef TASKS_H
#define TASKS_H

#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void free_all (char **args, int argc);
char **ft_dup (char **args, char **argv, int argc, int *index);
char	**ft_split(char const *str, char c);
size_t	count_words(char const *str, char delimeter);
void forking(int argc, char **args);

#endif