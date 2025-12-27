#include "ft_printf.h"
#include "limits.h"

int main(void)
{
	/*
	char a;
	//char *str;

	a = 'a';
	//str = "Banana split     ***";
	printf("*** TEST CHAR ***\n");
	ft_printf("Hello World, % #  10.2c\n", a);
	printf("printf:\nHello World, % #  10.2c\n\n", a);

	ft_printf("Hello World, % #---10.2c\n", a);
	printf("printf:\nHello World, % #---10.2c\n\n", a);

	printf("----------------------------------------------------\n");
	*/
	printf("*** TEST STRING ***\n");
	ft_printf("ft= %.s \n", "-");
	printf("p = %.s \n", "-");

	/*
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
	ft_printf("ft:\nPointer: %p\n%%", NULL);
	printf("printf:\nPointer: %p\n%%", NULL);

	printf("----------------------------------------------------\n");
	
	*/
	/*
	unsigned int h;

	h = 0;
	printf("*** TEST HEX ***\n");
	ft_printf("ft Hex: %-1x\n", h);
	printf("printf Hex: %-1x\n", h);

	ft_printf("ft Hex: %-1X\n", h);
	printf("printf Hex: %-1X\n", h);
	*/

	/*
	printf("----------------------------------------------------\n");

	unsigned int u = 9;
	printf("*** TEST UNSIGNED INT ***\n");
	ft_printf("ft:\nUnsigned: %#  ++10.2u\n", u);
	printf("printf:\nUnsigned: %#  ++10.2u\n", u);

	*/
	/*
	printf("----------------------------------------------------\n");

	int d;

	d = -14;
	printf("*** TEST INT ***\n");
	//ft_printf("ft:\nInt: %d %d %d %d %d %d\n", -10, INT_MAX, d, d, d, d);
	//printf("pritnf:\nInt: %d %d %d %d %d %d\n", -10, INT_MAX, d, d, d, d);

	ft_printf("ft:\nInt: %04i\n", d);
	printf("pritnf:\nInt: %04i\n", d);
	*/
	return 0;
}

