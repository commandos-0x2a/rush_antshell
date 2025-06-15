#ifndef TASKS_H
#define TASKS_H

#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
<<<<<<< HEAD:tasks/tasks.h
=======
#include <fcntl.h>
>>>>>>> refs/remotes/origin/main:shell00/tasks/tasks.h
#include <readline/readline.h>
#include <readline/history.h>

void free_all (char **args, int argc);
char **ft_dup (char **argv, int argc, int *index);
char	**ft_split(char const *str, char c);
size_t	count_words(char const *str, char delimeter);
void forking(int argc, char **args);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif