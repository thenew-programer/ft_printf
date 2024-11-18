#include "includes/ft_printf_bonus.h"
#include <limits.h>
#include <stdio.h>

int main()
{
    int	ret;
    ft_printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    ft_printf("%#x\n", LONG_MAX);
    printf("%#x\n", LONG_MAX);
    ret = ft_printf("%-1c", '0');
    printf("return = %d\n", ret);
    ret = printf("%-1c", '0');
    printf("return = %d\n", ret);
    ret = ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');
    printf("return = %d\n", ret);
    ret = printf(" %-1c %-2c %-3c ", '0', 0, '1');
    printf("return = %d\n", ret);
    ret = ft_printf(" %-1c %-2c %-3c ", '2', '1', 0);
    printf("return = %d\n", ret);
    ret = printf(" %-1c %-2c %-3c ", '2', '1', 0);
    printf("return = %d\n", ret);
    return (0);
}
