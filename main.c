#include "ft_printf.h"

int main(void)
{
	char a;
	char *str;

	a = 'a';
	str = "Banana split     ***";
	printf("*** TEST CHAR ***\n");
	//ft_printf("Hello World, % #  10.2c\n", a);
	printf("printf:\nHello World, % #  10.2c\n\n", a);

	ft_printf("Hello World, % #---10.2c\n", a);
	printf("printf:\nHello World, % #---10.2c\n\n", a);

	printf("----------------------------------------------------\n");

	printf("*** TEST STRING ***\n");
	printf("\n--- valid precision & width ---\n");
	ft_printf("String: %10.5s  \n", str);
	printf("String: %10.5s  \n", str);

	ft_printf("String: %  -###+++10.5s  \n", str);
	printf("String: %  -####+++10.5s  \n", str);

	printf("\n--- valid precision ---\n");
	ft_printf("String: %5.6s\n", str);
	printf("String: %5.6s\n", str);

	ft_printf("String: %----###   +++5.6s\n", str);
	printf("String: %----###   +++5.6s\n", str);

	printf("\n--- valid width ---\n");
	ft_printf("String: %#++ 006.5s\n", str);
	printf("String: %#++ 006.5s\n", str);

	ft_printf("String: %#++ 006.5s\n", str);
	printf("String: %#++ 006.5s\n", str);

	printf("\n--- no precision & width ---\n");
	ft_printf("String: %###00  s\n", str);
	ft_printf("String: %##00s\n", str);

	printf("----------------------------------------------------\n");

	printf("*** TEST POINTER ***\n");
	ft_printf("ft:\nPointer: %p\n%%", &a);
	printf("printf:\nPointer: %p\n%%", &a);

	printf("----------------------------------------------------\n");

	printf("*** TEST HEX ***\n");
	ft_printf("ft:\nHex: %x\n", 1234);
	printf("printf:\nHex: %x\n", 1234);

	ft_printf("ft:\nHex: %X\n", 1234);
	printf("printf:\nHex: %X\n", 1234);

	printf("----------------------------------------------------\n");

	unsigned int u = 42;
	printf("*** TEST UNSIGNED INT ***\n");
	ft_printf("ft:\nUnsigned: %#  ++10.2u\n", u);
	printf("ft:\nUnsigned: %#  ++10.2u\n", u);

	return 0;
}

