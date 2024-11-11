/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:03:01 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/10 12:05:09 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*_utoa(unsigned int n, char *buffer, size_t len)
{
	size_t	is_neg;
	size_t	buf_idx;

	buf_idx = len - 1;
	while (n)
	{
		buffer[buf_idx--] = (n % 10) + '0';
		n /= 10;
	}
	return (buffer);
}

char	*ft_utoa(unsigned int n)
{
	char	*number;
	int		len;

	len = numlen(n);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	number[len] = 0;
	if (n == 0)
	{
		number[0] = '0';
		return (number);
	}
	_utoa(n, number, len);
	return (number);
}
