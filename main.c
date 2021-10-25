#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include "sourc/libft.h"

int main()
{
	char **r = ft_split(" 111 222   333  ",' ');
	printf("%s %s %s\n", r[0],r[1],r[2]);
}




