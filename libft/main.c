#include "libft.h"
#include <stdio.h>
int	main(void)
{
	char *s1 = "12341234";
	char *s2 = "11111111";
	char *res = ft_strjoin(s1,s2);
	printf("%s\n",res);
}
