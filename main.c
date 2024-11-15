#include "ft_printf_bonus.h"
#include <stdio.h>

int	main()
{
    char    *str;
    int     nbr;
    str = "hello world";
    nbr = -13234937;

    // Category: String
    ft_printf("category s:\n");
    ft_printf("\tft_printf: |%.5s| \n", str);  // Precision flag
    // printf("\t   printf: |%.5s|\n\n", str);

    ft_printf("\tft_printf: |%-10s|\n", str);  // Left alignment flag
    // printf("\t   printf: |%-10s|\n\n", str);

    ft_printf("\tft_printf: |%.10s|\n", str);  // Precision flag
    // printf("\t   printf: |%.10s|\n\n", str);

    ft_printf("\tft_printf: |%10s|\n", str);  // Width flag (right-aligned)
    // printf("\t   printf: |%10s|\n\n", str);

    ft_printf("\tft_printf: NULL |%s| NULL \n", NULL);  // Handling NULL string
    // printf("\t   printf: NULL |%s| NULL \n", NULL);

    // Category: Pointer
//     ft_printf("category p:\n");
//     ft_printf("\tft_printf: str addr: %p\n", &str);  // Pointer
//     printf("\t   printf: str addr: %p\n\n", &str);
//
//     ft_printf("\tft_printf: str addr: %-20p\n", &str);  // Width flag (left-aligned pointer)
//     printf("\t   printf: str addr: %-20p\n\n", &str);
//
//     ft_printf("\tft_printf: str addr: %p\n", NULL);  // Handling NULL pointer
//     printf("\t   printf: str addr: %p\n\n", NULL);
//
//     // Category: Hexadecimal
//     ft_printf("category x,X:\n");
//     ft_printf("\tft_printf: %#x %#X\n", nbr, nbr);  // Hash flag (prefix with 0x/0X)
//     printf("\t   printf: %#x %#X\n\n", nbr, nbr);
//
//     ft_printf("\tft_printf: %05x %05X\n", nbr, nbr);  // Zero padding
//     printf("\t   printf: %05x %05X\n\n", nbr, nbr);
//
//     ft_printf("\tft_printf: %.5x %.5X\n", nbr, nbr);  // Precision flag
//     printf("\t   printf: %.5x %.5X\n\n", nbr, nbr);
//
//     ft_printf("\tft_printf: %-10x %-10X\n", nbr, nbr);  // Left alignment flag
//     printf("\t   printf: %-10x %-10X\n\n", nbr, nbr);
//
//     ft_printf("\tft_printf: %10x %10X\n", 0, 0);  // Width flag (right-aligned)
//     printf("\t   printf: %10x %10X\n\n", 0, 0);
//
//     // Category: Character
//     ft_printf("category c:\n");
//     ft_printf("\tft_printf: %c\n", '0');
//     printf("\t   printf: %c\n", '0');
//
//     ft_printf("\tft_printf: %-4c %c %4c\n", 'A', 'B', 'C');  // Left-alignment & width
//     printf("\t   printf: %-4c %c %4c\n", 'A', 'B', 'C');
//
//     ft_printf("\tft_printf: %02c %-4c %c\n", 'A', 'B', 'C');  // Zero padding & left-alignment
//     printf("\t   printf: %02c %-4c %c\n", 'A', 'B', 'C');
//
//     ft_printf("\tft_printf: %4c\n", 'Z');  // Width flag (right-aligned)
//     printf("\t   printf: %4c\n", 'Z');
//
//     // Category: Mixed case (mix of all categories with flags)
//     ft_printf("category mix:\n");
//     ft_printf("\tft_printf: %10s %-10s %04d %.5i % #X %+-10x\n", "42", "hello", 42, 42, nbr, nbr);  
//     printf("\t   printf: %10s %-10s %04d %.5i % #X %+-10x\n", "42", "hello", 42, 42, nbr, nbr);
//
//     ft_printf("\tft_printf: %-20p %20p %.10s\n", &str, &str, "test");
//     printf("\t   printf: %-20p %20p %.10s\n", &str, &str, "test");
//
//     ft_printf("\tft_printf: %10c %4c %02x\n", 'A', 'B', 255);  // Width & padding flags
//     printf("\t   printf: %10c %4c %02x\n", 'A', 'B', 255);
//
//     ft_printf("category NULL:\n");
//     printf(NULL);
//     ft_printf(NULL);
}
