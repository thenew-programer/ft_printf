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

t_token	*parse_fmt(const char *fmt, t_token **head)
{
	int	i;
	int	start;

	i = 0;
	while (fmt[i])
	{
		start = i;
		if (fmt[i] == '%')
		{
			while (!ft_strchar(SPS, fmt[i]) && fmt[i])
				i++;
			ft_tokenadd_back(head, ft_tokenew(ft_substr(fmt, start, i - start), T_SPEC));
		}
		else
		{
			while (fmt[i] != '%' && fmt[i])
				i++;
			ft_tokenadd_back(head, ft_tokenew(ft_substr(fmt, start, i - start),
					T_TEXT));
		}
	}
	return (*head);
}

void	parse_token(t_token *head)
{
	int	i;

	while (head)
	{
		i = 1;
		while (head->token[i] != '.' && !ft_strchar(SPS, head->token[i]))
		{
			if (head->token[i] == '-')
				head->flags.minus = ft_atoi(&head->token[i + 1]);
			else if (head->token[i] == '+')
				head->flags.plus = TRUE;
			else if (head->token[i] == '0' && !ft_isdigit(head->token[i - 1]))
				head->flags.zero = ft_atoi(&head->token[i + 1]);
			else if (head->token[i] == ' ')
				head->flags.space = TRUE;
			else if (head->token[i] == '#')
				head->flags.hash = TRUE;
			else if (head->token[i + 1] == '.')
				head->flags.precision = ft_atoi(&head->token[i + 1]);
			else
				head->flags.width = ft_atoi(&head->token[i]);
			i++;
		}
		head = head->next;
	}
}
