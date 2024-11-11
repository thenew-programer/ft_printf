#include "libftprintf.h"
#include <stdio.h>

int	main()
{
	char	*str;
	int		nbr;

	str = "hello world";
	nbr = -13234937;
	ft_printf("ft_printf: hello world %s\n", str);
	printf("   printf: hello world %s\n\n", str);
	ft_printf("ft_printf: str addr: %p\n", &str);
	printf("   printf: str addr: %p\n\n", &str);
	ft_printf("ft_printf: %x %X\n", nbr, nbr);
	printf("   printf: %x %X\n\n", nbr, nbr);
}
