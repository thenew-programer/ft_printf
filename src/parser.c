/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:37:25 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/07 17:21:34 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

t_token	*parse_fmt(const char *fmt, t_token **head)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	len = ft_strlen(fmt);
	start = i;
	while (i < len)
	{
		if (fmt[i] == '%')
		{
			ft_tokenadd_back(head, ft_tokenew(ft_substr(fmt, start, 1), T_SPEC));
			i += 2;
		}
		else
		{
			start = i;
			while (fmt[i] != '%' && i < len)
				i++;
			ft_tokenadd_back(head, ft_tokenew(ft_substr(fmt, start, i - start), T_TEXT));
		}
		i++;
	}
	return (*head);
}
