#include "libft.h"
int	count_numbers(int n)
{
	int	res;

	res = 0;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		minus;
	int		count;

	if (n == 0)
		return ("0");
	minus = 0;
	if (n < 0)
	{
		n *= -1;
		minus = 1;
	}
	count = count_numbers(n) + minus;
	if (!count)
		return (NULL);
	res = (char *) malloc(count);
	res[count] = 0;
	count--;
	while (n != 0)
	{
		res[count] = (char)((n % 10) + 48);
		n /= 10;
		count--;
	}
	if (minus > 0)
		res[count] = '-';
	return (res);
}
