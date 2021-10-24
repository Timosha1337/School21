#include <stdio.h>
#include "libft.h"
void	ft_bzero(void *str, size_t n)
{
	unsigned char	*strchar;

	strchar = (unsigned char *)str;
	while (n--)
	{
		*strchar = '\0';
		*strchar++;
	}
}
