#include "libft.h"
int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	const unsigned char	*arr1char;
	const unsigned char	*arr2char;

	arr1char = arr1;
	arr2char = arr2;
	while (n--)
	{
		if (*arr1char != *arr2char)
		{
			return ((int)*arr1char - *arr2char);
		}
		*arr1char++;
		*arr2char++;
	}
	return (0);
}
