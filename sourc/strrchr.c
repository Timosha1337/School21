#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	char	*value;

	while (*string || symbol == '\0' )
	{
		if (*string == symbol)
			value = (char *)string;
		if (*string == '\0')
			break ;
		*string++;
	}
	if (*value == symbol)
		return (value);
	return (NULL);
}
