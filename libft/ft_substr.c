#include "libft.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t		i;

	i = 0;
	sub = malloc(len);
	if (s == NULL || start > ft_strlen(s) || !sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
