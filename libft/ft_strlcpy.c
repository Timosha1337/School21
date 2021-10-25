#include "libft.h"
size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = n;
	if (n > 0)
	{
		while (i-- > 1 && *src)
			*dst++ = *src++;
		*dst++ = '\0';
	}
	while (src[i])
		i++;
	printf("%li\n", i + n - 1);
	return (i + n);
}
