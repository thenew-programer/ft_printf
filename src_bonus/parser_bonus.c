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
#include "ft_printf_bonus.h"

static void	parse_specifier(const char **fmt, char *specifier)
{
	if (ft_strchr(SPECS, **fmt))
	{
		*specifier = **fmt;
		(*fmt)++;
	}
}
static void	parse_precision(const char **fmt, t_flags *f)
{
	f->precision = 0;
	if (**fmt == '.')
	{
		(*fmt)++;
		while (ft_isdigit(**fmt))
		{
			f->precision = (f->precision * 10) + (**fmt - '0');
			(*fmt)++;
		}
	}
	else
		f->precision = -1;
}

static void	parse_flags(const char **fmt, t_flags *f)
{
	while (**fmt != '.' && !ft_strchr(SPECS, **fmt))
	{
		if (ft_strchr(FLAGS, **fmt))
		{
			if (**fmt == '-')
				f->flags |= FLAG_MINUS;
			if (**fmt == '+')
				f->flags |= FLAG_PLUS;
			if (**fmt == '0' && !ft_isdigit(*(*fmt - 1))
				&& !ft_check_flag(f->flags, FLAG_MINUS))
				f->flags |= FLAG_ZERO;
			if (**fmt == ' ')
				f->flags |= FLAG_SPACE;
			if (**fmt == '#')
				f->flags |= FLAG_HASH;
		}
		(*fmt)++;
		// while (ft_isdigit(**fmt))
		// {
		// 	f->width = (f->width * 10) + (**fmt - '0');
		// 	(*fmt)++;
		// }
	}
}

void	parse_width(const char **fmt, t_flags *f)
{
	while (ft_isdigit(**fmt))
	{
		f->width = (f->width * 10) + (**fmt - '0');
		(*fmt)++;
	}
}

void	parse_fmt(const char *fmt, t_token **head)
{
	int		end;
	t_token	*node;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			node = ft_tokenew(T_SPEC);
			parse_flags(&fmt, &node->f);
			parse_width(&fmt, &node->f);
			parse_precision(&fmt, &node->f);
			parse_specifier(&fmt, &node->specifier);
		}
		else
		{
			end = 0;
			while (fmt[end] && fmt[end] != '%')
				end++;
			node = ft_tokenew(T_TEXT);
			node->str = ft_substr(fmt, 0, end);
			fmt += end;
		}
		if (node)
			ft_tokenadd_back(head, node);
	}
}
