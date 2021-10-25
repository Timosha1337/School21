#include <stdlib.h>
#include "libft.h"

char	*get_wrd(char const *s, int start, int end)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(end - start);
	while (start < end)
		res[i++] = s[start++];
	res[i] = 0;
	return (res);
}

int	get_count_words(char const *s, char c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && !flag)
			flag = 1;
		if (s[i] == c && flag)
		{
			count++;
			flag = 0;
		}
		if (s[i + 1] == '\0' && flag)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		len;

	j = 0;
	i = 0;
	len = 0;
	res = (char **) malloc(get_count_words(s, c));
	while (s[i])
	{
		if (s[i + len] != c && s[i + len] != '\0')
			len++;
		else if (len > 0)
		{
			res[j] = get_wrd(s, i, len + i);
			i = len + i;
			len = 0;
			j++;
		}
		else
			i++;
	}
	return (res);
}
