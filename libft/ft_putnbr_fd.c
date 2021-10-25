# include <unistd.h>
#include "libft.h"
void	ft_putnbr_fd(int n, int fd)
{
	char	symb;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		symb = n + '0';
		write(fd, &symb, 1);
	}
}
