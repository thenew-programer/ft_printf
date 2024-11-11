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

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1])
			{
				ft_tokenadd_back(head, ft_tokenew(ft_substr(fmt, i, 2), T_SPEC));
				i += 2;
			}
			else
			{
				ft_tokenadd_back(head, ft_tokenew(ft_substr(fmt, i, 1), T_TEXT));
				i++;
			}
		}
		else
		{
			start = i;
			while (fmt[i] != '%' && fmt[i])
				i++;
			ft_tokenadd_back(head, ft_tokenew(ft_substr(fmt, start, i - start), T_TEXT));
		}
	}
	return (*head);
}
