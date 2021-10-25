#include "libft.h"
void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*strchar;

	if (str == NULL)
		return (NULL);
	strchar = (unsigned char *) str;
	while (n > 0)
	{
		*strchar = (unsigned char) c;
		strchar++;
		n--;
	}
	return (strchar);
}
