/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:02:01 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/11 10:15:25 by ybouryal         ###   ########.fr       */
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
