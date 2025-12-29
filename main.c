#include "ft_printf.h"
#include <limits.h>

int main (void)
{
	char str[INT_MAX + 1];

	str = memset(str, '0', INT_MAX);
	str[INT_MAX + 1] = '\0';

	ft_printf("%s, str);

	return 0;
}
