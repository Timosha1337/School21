#include "libft.h"

int	ft_math(char s1, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (s1 == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		i;
	int		end;
	char	*res;

	start = 0;
	i = 0;
	end = (int)ft_strlen(s1);
	while (s1[start] && ft_math(s1[start], set))
		start++;
	while (end - 1 > start && ft_math(s1[end - 1], set))
		end--;
	res = malloc(end - start);
	while (start < end)
		res[i++] = s1[start++];
	res[i] = 0;
	return (res);
}
