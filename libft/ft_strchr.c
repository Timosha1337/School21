#include "libft.h"
char	*ft_strchr(const char *string, int symbol)
{
	char	*value;

	value = (char *)string;
	while (*value != symbol)
		value++;
	if (*value == symbol)
		return (value);
	return (NULL);
}
