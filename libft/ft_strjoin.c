#include "libft.h"
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		i;

	i = 0;
	concat = malloc(ft_strlen(s1) + ft_strlen(s2));
	if (!concat)
		return (NULL);
	while (*s1)
	{
		concat[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		concat[i] = *s2;
		i++;
		s2++;
	}
	concat[i] = 0;
	return (concat);
}
