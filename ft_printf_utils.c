#include "ft_printf.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(*str)
	{
		i++;
		str++;
	}
	return i;
}

char *ft_memset(char *str, int c, size_t n)
{
	int i;

	i = 0;
	while(n > 0)
	{
		str[i] = c;
		n--;
		i++;
	}
	return str;
}

char *ft_memcpy(char *dest, char *src, size_t n)
{
	int i;

	i = 0;
	while(n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	return dest;
}
