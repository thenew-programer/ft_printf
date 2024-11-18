/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:16:34 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/11 10:13:38 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

int	ft_check_flag(int flags, int flag)
{
	if ((flags & flag) == flag)
		return (TRUE);
	return (FALSE);
}

int	ft_strchar(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

size_t	ft_num_len(unsigned long nb, size_t base)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char	*ft_putptr(uintptr_t ptr)
{
	char	*hex;
	char	*buffer;
	size_t	numlen;
	int		buf_idx;

	hex = "0123456789abcdef";
	numlen = ft_num_len(ptr, 16);
	buffer = (char *)malloc(sizeof(char) * (numlen + 3));
	buffer[0] = '0';
	buffer[1] = 'x';
	buffer[numlen + 2] = '\0';
	buf_idx = numlen + 1;
	while (ptr && buf_idx >= 0)
	{
		buffer[buf_idx--] = hex[ptr % 16];
		ptr /= 16;
	}
	return (buffer);
}

char	*ft_print_hex(char *base, unsigned int num)
{
	char	*buffer;
	int		numlen;
	size_t	baselen;

	if (num == 0)
		return (ft_strdup("0"));
	baselen = ft_strlen(base);
	numlen = ft_num_len(num, baselen);
	buffer = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!buffer)
		return (NULL);
	buffer[numlen--] = '\0';
	while (num && numlen >= 0)
	{
		buffer[numlen--] = base[num % baselen];
		num /= baselen;
	}
	return (buffer);
}

void	handle_width(t_token *elem)
{
	char	*width;
	char	*tmp;
	int		len;

	if (!*elem->str)
		elem->f.width--;
	len = elem->f.width - ft_strlen(elem->str);
	if (elem->f.width <= 0 || len <= 0)
		return ;
	width = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!width)
	  return ;
	tmp = elem->str;
	if (ft_check_flag(elem->f.flags, FLAG_ZERO) && (elem->specifier != 's'
		|| elem->specifier != 'c'))
	{
		ft_memset(width, '0', len);
		elem->str = ft_strjoin(width, tmp);
		return (free(tmp), free(width));
	}
	ft_memset(width, ' ', len);
	if (ft_check_flag(elem->f.flags, FLAG_MINUS))
		elem->str = ft_strjoin(tmp, width);
	else
		elem->str = ft_strjoin(width, tmp);
	free(width);
	free(tmp);
}

char	*int_precision(char *str, int prc)
{
	char	*precision;
	int		len;

	len = prc - ft_strlen(str);
	precision = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!precision)
		return (NULL);
	ft_memset(precision, '0', len);
	str = ft_strjoin(precision, str);
	free(precision);
	return (str);
}

void	handle_precision(t_token *elem)
{
	char	*tmp;

	if (elem->f.precision <= 0 || !*elem->str)
		return ;
	tmp = elem->str;
	if (ft_strchr("diu", elem->specifier))
		elem->str = int_precision(elem->str, elem->f.precision);
	else if (ft_strchr("s", elem->specifier))
	{
		if (ft_strlen(elem->str) >= (size_t)elem->f.precision)
			return ;
		elem->str = ft_substr(elem->str, 0, elem->f.precision);
	}
	free(tmp);
}
