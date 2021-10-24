#include "libft.h"
char	*ft_strstr(const char *src, const char *sought)
{
	int		i;
	char	*c;

	i = 0;
	while (*src != '\0')
	{
		if (*src == sought[i])
		{
			if (i == 0)
				c = (char *)src;
			i++;
			if (sought[i] == '\0')
				return (c);
		}
		else
			i = 0;
		*src++;
	}
	return (NULL);
}
