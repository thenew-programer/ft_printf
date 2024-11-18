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
#include "ft_printf_bonus.h"

void	eval_char(t_token *elem)
{
	elem->str = (char *)malloc(sizeof(char) * 2);
	if (!elem->str)
		return ;
	elem->str[0] = elem->data.c;
	elem->str[1] = '\0';
	if (elem->data.c == 0)
		elem->len++;
	handle_width(elem);
}

void	eval_str(t_token *elem)
{
	if (!elem->data.str)
	{
		elem->str = ft_strdup("(null)");
		return ;
	}
	elem->str = ft_strdup(elem->data.str);
	if (!elem->str)
		return ;
	handle_precision(elem);
	handle_width(elem);
}

void	eval_int(t_token *elem)
{
	char	*tmp;

	elem->str = ft_itoa(elem->data.i);
	if (ft_check_flag(elem->f.flags, FLAG_PLUS) && elem->data.i > 0
		&& !ft_check_flag(elem->f.flags, FLAG_ZERO))
	{
		tmp = elem->str;
		elem->str = ft_strjoin("+", elem->str);
		free(tmp);
	}
	if (!elem->str)
		return ;
	handle_width(elem);
	handle_precision(elem);
}

void	eval_uint(t_token *elem)
{
	elem->str = ft_utoa(elem->data.u);
	handle_width(elem);
	handle_precision(elem);
}
