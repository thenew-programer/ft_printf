/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:25:18 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/10 12:29:40 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

void	assign_args(t_token *head, va_list args)
{
	char	sp;

	while (head)
	{
		sp = head->specifier;
		if (head->type == T_SPEC)
		{
			if (sp == 'd' || sp == 'i')
				head->data.i = va_arg(args, int);
			else if (sp == 'u' || sp == 'x'
				|| sp == 'X')
				head->data.u = va_arg(args, unsigned int);
			else if (sp == 'c')
				head->data.c = va_arg(args, int);
			else if (sp == 's')
				head->data.str = va_arg(args, char *);
			else if (sp == 'p')
				head->data.ptr = va_arg(args, void *);
		}
		head = head->next;
	}
	va_end(args);
}

int	print_res(t_token *head)
{
	t_token	*curr;
	int		len;

	len = 0;
	while (head)
	{
		curr = head;
		write(1, curr->str, curr->len);
		len += curr->len;
		head = head->next;
	}
	return (len);
}

void	init_spec(t_spec *specs)
{
	specs[0] = (t_spec){'c', eval_char};
	specs[1] = (t_spec){'s', eval_str};
	specs[2] = (t_spec){'d', eval_int};
	specs[3] = (t_spec){'i', eval_int};
	specs[4] = (t_spec){'u', eval_uint};
	specs[5] = (t_spec){'x', eval_hex};
	specs[6] = (t_spec){'X', eval_hex};
	specs[7] = (t_spec){'p', eval_ptr};
	specs[8] = (t_spec){'%', eval_percent};
	specs[9] = (t_spec){0, NULL};
}

int	ft_printf(const char *fmt, ...)
{
	t_token	*tokens;
	// t_token	*tmp;
	t_spec	specs[10];
	va_list	args;
	int		printlen;

	if (!fmt)
		return (-1);
	tokens = NULL;
	init_spec(specs);
	parse_fmt(fmt, &tokens);
	va_start(args, fmt);
	assign_args(tokens, args);
	tokens = eval_fmt(&tokens, specs);
	if (!tokens)
		return (0);
	// tmp = tokens;
	// printlen = 0;
	// while (tmp)
	// {
	// 	if (tmp->type == T_TEXT)
	// 		printlen += printf("%s\n", tmp->str);
	// 	else
	// 	{
	// 		printf("specifier	= %c\n", tmp->specifier);
	// 		printf("precision	= %d\n", tmp->f.precision);
	// 		printf("width		= %d\n", tmp->f.width);
	// 	}
	// 	tmp = tmp->next;
	// }
	printlen = print_res(tokens);
	ft_tokenclear(&tokens, free);
	return (printlen);
}
