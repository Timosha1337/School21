#include "libft.h"
int	ft_isascii(int ch)
{
	if (ch >= 0 && ch <= 126)
		return (1);
	return (0);
}
