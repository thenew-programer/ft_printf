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

#include "libft.h"
#include "ft_printf.h"

char	*eval_spec(const char *token, t_spec_data data, t_spec *specs)
{
	int		len;
	char	*str;
	int		i;

	len = ft_strlen(token);
	i = 0;
	while (specs[i].specifier != 0)
	{
		if (token[len - 1] == specs[i].specifier)
		{
			str = specs[i].eval(token, data);
			if (!str)
				return (ft_strdup("(null)"));
			return (str);
		}
		i++;
	}
	return (NULL);
}

t_token	*eval_fmt(t_token **head, t_spec *specs)
{
	t_token *curr;

	curr = *head;
	while (curr)
	{
		if (curr->type == T_SPEC)
		{
			curr->str = eval_spec(curr->token, curr->data, specs);
			if (!curr->str)
			{
				curr->str = curr->token;
				curr->token = NULL;
			}
		}
		else
		{
			curr->str = curr->token;
			curr->token = NULL;
		}
		curr->strlen = ft_strlen(curr->str);
		curr = curr->next;
	}
	return (*head);
}

void	assign_args(t_token *head, va_list args)
{
	size_t	len;
	char	*token;

	while (head)
	{
		token = head->token;
		len = ft_strlen(head->token);
		if (head->type == T_SPEC)
		{
			if (token[len - 1] == 'd'  || token[len - 1] == 'i')
				head->data.i = va_arg(args, int);
			else if (token[len - 1] == 'u'  || token[len - 1] == 'x'
				|| token[len - 1] == 'X')
				head->data.u = va_arg(args, unsigned int);
			else if (token[len - 1] == 'c')
				head->data.c = va_arg(args, int);
			else if (token[len - 1] == 's')
				head->data.str = va_arg(args, char *);
			else
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
		len += write(1, curr->str, curr->strlen);
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
	specs[6] = (t_spec){'X', eval_HEX};
	specs[7] = (t_spec){'p', eval_ptr};
	specs[8] = (t_spec){'%', eval_percent};
	specs[9] = (t_spec){0, NULL};
}

int	ft_printf(const char *fmt, ...)
{
	t_token	*tokens;
	t_spec	specs[10];
	va_list args;
	int		printlen;

	tokens = NULL;
	init_spec(specs);
	parse_fmt(fmt, &tokens);
	va_start(args, fmt);
	assign_args(tokens, args);
	tokens = eval_fmt(&tokens, specs);
	if (!tokens)
		return (0);
	printlen = print_res(tokens);
	ft_tokenclear(&tokens, free);
	return (printlen);
}
