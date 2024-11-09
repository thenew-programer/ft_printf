/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:37:34 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/06 11:42:59 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	check_format(const char *fmt)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && !ft_strchr(SPS, fmt[i + 1]))
			return (FALSE);
		if (fmt[i] == '%' && fmt[i + 1] == '%')
			i++;
		i++;
	}
	return (TRUE);
}
