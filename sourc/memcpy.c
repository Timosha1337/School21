#include "libft.h"
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destchar;
	unsigned char	*srchar;

	destchar = (unsigned char *) dest;
	srchar = (unsigned char *) src;
	while (n--)
		*destchar++ = *srchar++;
	return (dest);
}
