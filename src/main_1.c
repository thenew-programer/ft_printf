#include "libftprintf.h"
#include <stdio.h>

int	main()
{
	char	*str;
	int		nbr;

	nbr = 132349347;
	ft_printf("ft_printf: hello world %s non-str\n", str);
	// printf("   printf: hello world %s\n\n", str);
	ft_printf("ft_printf: str addr: %p non-str\n", &str);
	// printf("   printf: str addr: %p\n\n", &str);
	ft_printf("ft_printf: %x %X non-str\n", nbr, nbr);
	// printf("   printf: %x %X\n\n", nbr, nbr);
}
