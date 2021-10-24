#include "libft.h"
char	*ft_strdup(const char *str)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	res = malloc(ft_strlen(str));
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
