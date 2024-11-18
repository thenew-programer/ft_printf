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

#include "ft_printf_bonus.h"
#include "libft.h"

void	eval_ptr(t_token *elem)
{
	if (!elem->data.ptr)
	{
		elem->str = ft_strdup("(nil)");
		return ;
	}
	elem->str = ft_putptr((uintptr_t)elem->data.ptr);
	handle_width(elem);
}

void	eval_hex(t_token *elem)
{
	char	*tmp;

	if (elem->specifier == 'x')
		elem->str = ft_print_hex("0123456789abcdef", elem->data.u);
	else if (elem->specifier == 'X')
		elem->str = ft_print_hex("0123456789ABCDEF", elem->data.u);
	if ((elem->f.flags & FLAG_ZERO) == FLAG_ZERO)
		handle_width(elem);
	if ((elem->f.flags & FLAG_HASH) == FLAG_HASH && elem->data.u > 0)
	{
		tmp = elem->str;
		if (elem->specifier == 'x')
			elem->str = ft_strjoin("0x", elem->str);
		else if (elem->specifier == 'X')
			elem->str = ft_strjoin("0X", elem->str);
		free(tmp);
	}
	if ((elem->f.flags & FLAG_ZERO) != FLAG_ZERO)
		handle_width(elem);
}

void	eval_percent(t_token *elem)
{
	elem->str = (char *)malloc(sizeof(char) * 2);
	if (!elem->str)
		return ;
	elem->str[0] = '%';
	elem->str[1] = '\0';
}

void	eval_spec(t_token *elem, t_spec *specs)
{
	int		i;

	i = 0;
	while (specs[i].specifier != 0)
	{
		if (elem->specifier == specs[i].specifier)
		{
			specs[i].eval(elem);
			return ;
		}
		i++;
	}
}

t_token	*eval_fmt(t_token **head, t_spec *specs)
{
	t_token	*curr;

	curr = *head;
	while (curr)
	{
		if (curr->type == T_SPEC)
			eval_spec(curr, specs);
		if (curr->str)
			curr->len += ft_strlen(curr->str);
		curr = curr->next;
	}
	return (*head);
}
