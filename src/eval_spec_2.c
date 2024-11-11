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

#include "ft_printf.h"
#include "libft.h"

char	*eval_ptr(const char *token, t_spec_data data)
{
	char	*str;

	(void)token;
	if (!data.ptr)
		return (ft_strdup("(nil)"));
	str = ft_putptr((uintptr_t)data.ptr);
	return (str);
}

char	*eval_hex(const char *token, t_spec_data data)
{
	char	*str;

	(void)token;
	str = ft_print_hex("0123456789abcdef", data.u);
	return (str);
}

char	*eval_HEX(const char *token, t_spec_data data)
{
	char	*str;

	(void)token;
	str = ft_print_hex("0123456789ABCDEF", data.u);
	return (str);
}

char	*eval_percent(const char *token, t_spec_data data)
{
	char	*str;

	(void)token;
	(void)data;
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}
