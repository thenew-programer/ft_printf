/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_spec_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:46:47 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/11 10:12:05 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*eval_char(const char *token, t_spec_data data)
{
	char	*str;

	(void)token;
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = data.c;
	str[1] = '\0';
	return (str);
}

char	*eval_str(const char *token, t_spec_data data)
{
	char	*str;

	(void)token;
	str = ft_strdup(data.str);
	return (str);
}

char	*eval_int(const char *token, t_spec_data data)
{
	char	*str;

	(void)token;
	str = ft_itoa(data.i);
	return (str);
}

char	*eval_uint(const char *token, t_spec_data data)
{
	char	*str;

	(void)token;
	str = ft_utoa(data.u);
	return (str);
}
