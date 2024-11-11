/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:14:17 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/08 18:17:42 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int	ft_nbrlen(uintptr_t ptr, int base)
{
	int	len;

	len = 0;
	while (ptr)
	{
		len++;
		ptr /= base;
	}
	return (len);
}
