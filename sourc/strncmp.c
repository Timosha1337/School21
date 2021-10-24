#include "libft.h"
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n)
	{
		if (str1[n] > str2[n])
			return (1);
		else if (str1[n] < str2[n])
			return (-1);
		else
			return (0);
		n--;
	}
}
