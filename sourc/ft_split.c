# include <stdlib.h>
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
	int		flag;
	int		startfinish[2];
	int		j;

	j = 0;
	i = 0;
	flag = 0;
	res = (char **) malloc(get_count_words(s, c));
	while (s[i])
	{
		if (s[i] != c && !flag)
		{
			flag = 1;
			startfinish[0] = i;
		}
		if (s[i] == c && flag)
		{
			flag = 0;
			startfinish[1] = i;
		}
		if (s[i + 1] == '\0' && flag)
			startfinish[1] = i;
		if (startfinish[1] > startfinish[0])
		{
			res[j] = get_wrd(s, startfinish[0], startfinish[1]);
			j++;
			startfinish[0] = 0;
			startfinish[1] = 0;
		}
		i++;
	}
	return (res);
}
