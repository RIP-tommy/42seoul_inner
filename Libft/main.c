#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

char	mapi(unsigned int i, char c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int main()
{
	char	*str;
	char	*strmapi;

	str = (char *)malloc(sizeof(*str) * 12);
	strcpy(str, "LoReM iPsUm");
	strmapi = ft_strmapi(str, &mapi);
	ft_print_result(strmapi);
	if (strmapi == str)
		ft_print_result("\nA new string was not returned");
	if (strmapi[11] != '\0')
		ft_print_result("\nString is not null terminated");
	return (0);
}
