#include "libft.h"
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstsize;
	size_t	i;

	i = 0;
	dstsize = ft_strlen(dst);
	if (src != NULL)
	{
		while (src[i] && dstsize + i < size - 1)
		{
			dst[i + dstsize] = src[i];
			i++;
		}
		dst[i + dstsize] = 0;
	}
	if (dstsize > size)
		dstsize = size;
	return (dstsize + ft_strlen(src));
}
