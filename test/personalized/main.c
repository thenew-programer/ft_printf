#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char	*str;
	int		ret;
	int		nbr;

	str = "hello world";
	nbr = -13234937;
	ft_printf("category s:\n");
	ft_printf("\tft_printf: hello world %s\n", str);
	printf("\t   printf: hello world %s\n\n", str);
	ft_printf("\tft_printf: NULL %s NULL \n", NULL);
	printf("\t   printf: NULL %s NULL \n", NULL);

	ft_printf("category p:\n");
	ft_printf("\tft_printf: str addr: %p\n", &str);
	printf("\t   printf: str addr: %p\n\n", &str);
	ft_printf("\tft_printf: str addr: %p\n", NULL);
	printf("\t   printf: str addr: %p\n\n", NULL);

	ft_printf("category x,X:\n");
	ft_printf("\tft_printf: %x %X\n", nbr, nbr);
	printf("\t   printf: %x %X\n\n", nbr, nbr);
	ft_printf("\tft_printf: %x %X\n", 0, 0);
	printf("\t   printf: %x %X\n\n", 0, 0);

	ft_printf("category c:\n");
	ft_printf("\tft_printf: %c\n", '0');
	printf("\t   printf: %c\n", '0');
	ret = ft_printf("\tft_printf: %c %c %c ", '0', 0, '1');
	printf("return = %i\n", ret);
	ret = printf("\t   printf: %c %c %c ", '0', 0, '1');
	printf("return = %i\n", ret);
	ft_printf("\tft_printf: %c %c %c \n", '2', '1', 0);
	printf("\t   printf: %c %c %c \n", '2', '1', 0);
	ft_printf("\tft_printf: %c %c %c \n", 0, '1', '2');
	printf("\t   printf: %c %c %c \n", 0, '1', '2');

	ft_printf("category mix:\n");
	ret = printf("\t   printf: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%"
	   , 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("return = %i\n", ret);
	ret = ft_printf("\tft_printf: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%",
	   'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("return = %i\n", ret);

	ft_printf("category NULL:\n");
	ret = printf(NULL);
	printf("return = %i\n", ret);
	ret = ft_printf(NULL);
	printf("return = %i\n", ret);
}
