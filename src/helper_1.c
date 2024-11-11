/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:16:34 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/11 10:13:38 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	ft_strchar(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

size_t	ft_num_len(unsigned long nb, size_t base)
{
	size_t	len;

	len = 0;
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char	*ft_putptr(uintptr_t ptr)
{
	char	*hex;
	char	*buffer;
	size_t	numlen;
	int		buf_idx;

	hex = "0123456789abcdef";
	numlen = ft_num_len(ptr, 16);
	buffer = (char *)malloc(sizeof(char) * (numlen + 3));
	buffer[0] = '0';
	buffer[1] = 'x';
	buffer[numlen + 2] = '\0';
	buf_idx = numlen + 1;
	while (ptr && buf_idx >= 0)
	{
		buffer[buf_idx--] = hex[ptr % 16];
		ptr /= 16;
	}
	return (buffer);
}

char	*ft_print_hex(char *base, int num)
{
	char	*buffer;
	int		numlen;
	size_t	baselen;


	baselen = ft_strlen(base);
	numlen = ft_num_len(num, baselen);
	buffer = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!buffer)
		return (NULL);
	buffer[numlen--] = '\0';
	while (num && numlen >= 0)
	{
		buffer[numlen--] = base[num % baselen];
		num /= baselen;
	}
	return (buffer);
}

char	*ft_nil_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 9);
	if (!str)
		return (NULL);
	ft_strlcpy(str, "((null))", 9);
	return (str);
}
