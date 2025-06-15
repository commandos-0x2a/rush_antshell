#include "antshell.h"

size_t	count_words(char const *str, char delimeter);
static int		safe_malloc(char **arr, int position, size_t size);
static int		fill(char **arr, char const *str, char delimeter);

char	**ft_split(char const *str, char c)
{
	size_t	words;
	char	**arr;

	if (NULL == str)
		return (NULL);
	words = 0;
	words = count_words(str, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (NULL == arr)
		return (NULL);
	arr[words] = NULL;
	if (fill(arr, str, c))
		return (NULL);
	return (arr);
}

static int	safe_malloc(char **arr, int position, size_t size)
{
	int	i;

	i = 0;
	arr[position] = malloc(size);
	if (NULL == arr[position])
	{
		while (i < position)
			free(arr[i++]);
		free(arr);
		return (1);
	}
	return (0);
}

// return 0 if all mallocs went fine, otherwise 1
static int	fill(char **arr, char const *str, char delimeter)
{
	size_t	word_len;
	int		i;

	i = 0;
	while (*str)
	{
		word_len = 0;
		while (*str == delimeter && *str)
			++str;
		while (*str != delimeter && *str)
		{
			++word_len;
			++str;
		}
		if (word_len)
		{
			if (safe_malloc(arr, i, word_len + 1))
				return (1);
			strncpy(arr[i], str - word_len, word_len + 1);
			arr[i][word_len] = '\0';
		}
		++i;
	}
	return (0);
}

size_t	count_words(char const *str, char delimeter)
{
	size_t	word;
	int		inside_word;

	word = 0;
	while (*str)
	{
		inside_word = 0;
		while (*str == delimeter && *str)
			++str;
		while (*str != delimeter && *str)
		{
			if (!inside_word)
			{
				++word;
				inside_word = 1;
			}
			++str;
		}
	}
	return (word);
}
