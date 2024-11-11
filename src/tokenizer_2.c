/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:15:14 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/11 10:15:20 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tokenadd_back(t_token **head, t_token *new)
{
	t_token	*last;

	if (*head == NULL)
		*head = new;
	else
	{
		last = ft_tokenlast(*head);
		if (last)
			last->next = new;
	}
}

void	ft_tokendelone(t_token *elem, void (*del)(void *))
{
	if (del)
	{
		if (elem->str)
			del(elem->str);
		if (elem->token)
			del(elem->token);
	}
	elem->next = NULL;
	free(elem);
}

void	ft_tokenclear(t_token **head, void (*del)(void *))
{
	t_token	*cur;

	if (*head == NULL)
		return ;
	while (*head)
	{
		cur = (*head);
		(*head) = (*head)->next;
		ft_tokendelone(cur, del);
	}
	*head = NULL;
}
