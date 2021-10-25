#include "libft.h"

int	ft_negativ(int i)
{
	if (i < 0)
		return (1);
	return (0);
}

int	ft_count_numbers(int n)
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
	int		count;

	if (n == 0)
		return ("0");
	count = ft_count_numbers(n) + ft_negativ(n);
	n *= -1;
	res = (char *) malloc(count);
	if (!res)
		return (NULL);
	res[count] = 0;
	count--;
	while (n != 0)
	{
		res[count] = (char)((n % 10) + 48);
		n /= 10;
		count--;
	}
	if (count >= 0)
		res[count] = '-';
	return (res);
}
