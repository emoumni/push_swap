#include "push_swap.h"

static	int	countw(const char *s, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static void	free_mem(char **aux, int k)
{
	while (k >= 0)
	{
		free(aux[k]);
		k--;
	}
	free(aux);
}

char	**ft_split(char const *s, char c)
{
	char	**aux;
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	aux = (char **)malloc(sizeof (char *) * (countw((char *) s, c) + 1));
	if (!aux)
		return (0);
	while (s[i] && k < countw(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		aux[k++] = ft_substr(s, j, i - j);
		if (!aux)
			return (free_mem(aux, k), NULL);
	}
	aux[k++] = NULL;
	return (aux);
}
