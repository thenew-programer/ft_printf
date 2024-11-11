/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_spec_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:11:36 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/11 10:11:56 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*eval_ptr(const char *token, void *data)
{
	char	*str;

	str = ft_putptr((uintptr_t)data);
	return (str);
}

char	*eval_hex(const char *token, void *data)
{
	char	*str;

	if (!data)
		return (NULL);
	str = print_hex("0123456789abcdef", (intptr_t)data);
	return (str);
}

char	*eval_HEX(const char *token, void *data)
{
	char	*str;

	if (!data)
		return (NULL);
	str = print_hex("0123456789ABCDEF", (intptr_t)data);
	return (str);
}

char	*eval_percent(const char *token, void *data)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}
