#include "libft.h"
void	*ft_memmove( void *str1, const void *str2, size_t n )
{
	unsigned char		*str1char;
	const unsigned char	*str2char;
	unsigned char		current;
	unsigned char		next;

	str1char = (unsigned char *) str1;
	str2char = (const unsigned char *) str2;
	if (str1 < str2)
	{
		while (n--)
		{
			*str1char++ = *str2char++;
		}
	}
	else
	{
		current = *str2char;
		while (n--)
		{
			next = *str1char;
			*str1char++ = current;
			current = next;
		}
	}
	return (str1);
}
