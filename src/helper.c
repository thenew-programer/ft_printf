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
