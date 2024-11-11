/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:16:34 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/07 17:17:21 by ybouryal         ###   ########.fr       */
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

char	*putptr(t_byte *addr)
{
	char	*hex;
	char	*buffer;
	int		buf_idx;
	int		i;

	hex = "0123456789abcdef";
	buf_idx = 0;
	i = sizeof(void *) - 1;

	while (i >= 0)
	{
		buffer[buf_idx++] = hex[(addr[i] >> 4) & 0xF];
		buffer[buf_idx++] = hex[addr[i] & 0xF];
		i--;
	}
	buffer[buf_idx] = '\0';
	return (buffer);
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

char	*print_hex(char *base, int num)
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
