#include "libft.h"
int	ft_atoi(const char *str)
{
	int	res;
	int	ngt;

	res = 0;
	ngt = 1;
	if (!str)
		return (0);
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		*str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ngt = -1;
		*str++;
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res * ngt);
}
