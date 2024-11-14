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

char	*eval_ptr(const char *token, t_spec_data data)
{
	char	*str;

	(void)token;
	if (!data.ptr)
		return (ft_strdup("(nil)"));
	str = ft_putptr((uintptr_t)data.ptr);
	return (str);
}

char	*eval_hex(const char *token, t_spec_data data)
{
	char	*str;
	size_t	len;

	len = ft_strlen(token);
	if (token[len - 1] == 'x')
		str = ft_print_hex("0123456789abcdef", data.u);
	else
		str = ft_print_hex("0123456789ABCDEF", data.u);
	return (str);
}

char	*eval_percent(const char *token, t_spec_data data)
{
	char	*str;

	(void)token;
	(void)data;
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}

char	*eval_spec(const char *token, t_spec_data data, t_spec *specs)
{
	int		len;
	char	*str;
	int		i;

	len = ft_strlen(token);
	if (len == 0)
		len = 1;
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
	t_token	*curr;

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
