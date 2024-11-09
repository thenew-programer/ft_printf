/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:46:47 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/08 11:55:33 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

char	*eval_char(const char *token, void *data)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = *((char *)data);
	str[1] = '\0';
	return (str);
}
char	*eval_str(const char *token, void *data)
{
	char	*str;

	str = ft_strdup((char *)data);
	return (str);
}
char	*eval_int(const char *token, void *data)
{
	char	*str;

	str = ft_itoa(*((int *)data));
	return (str);
}
char	*eval_uint(const char *token, void *data)
{
	char	*str;

	str = ft_itoa(*((unsigned int *)data));
	return (str);

}
char	*eval_ptr(const char *token, void *data)
{
	char	*str;

	return (str);

}
char	*eval_hex(const char *token, void *data)
{
	char	*str;

	return (str);

}
char	*eval_HEX(const char *token, void *data)
{
	char	*str;

	return (str);

}
