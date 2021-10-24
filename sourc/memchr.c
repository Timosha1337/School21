#include "libft.h"
void	*ft_memchr(const void *arr, int c, size_t n)
{
	const unsigned char	*arrchar;

	arrchar = arr;
	if (arr == NULL)
		return (NULL);
	while (n--)
	{
		if (*arrchar == (unsigned char)c)
			return ((void *)arrchar);
		*arrchar++;
	}
	return (NULL);
}
