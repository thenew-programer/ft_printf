/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:02:01 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/07 17:11:14 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_token	*ft_tokenew(char *token, int type)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->token = token;
	new->str = NULL;
	new->next = NULL;
	new->data = NULL;
	new->type = type;
	return (new);
}

t_token	*ft_tokenlast(t_token *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	ft_tokensize(t_token *head)
{
	int	len;

	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

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
