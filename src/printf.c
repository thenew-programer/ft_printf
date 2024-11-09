/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:25:18 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/08 18:23:39 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

char	*eval_spec(const char *token, void	*data, t_spec *specs)
{
	int	len;
	int	i;

	len = ft_strlen(token);
	while (specs[i].specifier != 0)
	{
		if (token[len - 1] == specs[i].specifier)
			return (specs[i].eval(token, data));
	}
	return (NULL);
}

void	eval_fmt(t_token *head, t_spec *specs)
{
	t_token *curr;

	while (head->next)
	{
		curr = head;
		if (curr->type == T_SPEC)
		{
			curr->str = eval_spec(curr->token, curr->data, specs);
			free(curr->token);
		}
		else
			curr->str = curr->token;
		curr->token = NULL;
		head = head->next;
	}
}

void	assign_args(const char *fmt, t_token *head, va_list args)
{
	t_token *curr;

	while (head->next)
	{
		curr = head;
		if (curr->type == T_SPEC)
			curr->data = va_arg(args, void *);
		else
			curr->data = NULL;
		head = head->next;
	}
}

void	init_spec(t_spec specs[10])
{
	specs[0] = (t_spec){'c', NULL};
	specs[1] = (t_spec){'s', NULL};
	specs[2] = (t_spec){'d', NULL};
	specs[3] = (t_spec){'i', NULL};
	specs[4] = (t_spec){'u', NULL};
	specs[5] = (t_spec){'x', NULL};
	specs[6] = (t_spec){'X', NULL};
	specs[7] = (t_spec){'p', NULL};
	specs[8] = (t_spec){'%', NULL};
	specs[9] = (t_spec){0, NULL};
}

int	ft_printf(const char *fmt, ...)
{
	int		n_tkns;
	t_token	*tokens;
	t_spec	specs[10];
	va_list args;

	tokens = NULL;
	init_spec(specs);
	parse_fmt(fmt, &tokens);
	va_start(args, fmt);
	assign_args(fmt, tokens, args);
	n_tkns = ft_tokensize(tokens);
	eval_fmt(tokens, specs);
	return (0);
}
