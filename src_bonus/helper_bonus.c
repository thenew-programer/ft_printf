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

	if (elem->f.width <= 0)
		return ;
	len = elem->f.width - ft_strlen(elem->str);
	if (len <= 0)
		return ;
	width = (char *)malloc(sizeof(char) * (len + 1));
	if (!width)
	  return ;
	width[len] = '\0';
	if ((elem->f.flags & FLAG_ZERO) == FLAG_ZERO)
		ft_memset(width, 48, len);
	else
		ft_memset(width, 32, len);
	tmp = elem->str;
	if ((elem->f.flags & FLAG_MINUS) == FLAG_MINUS)
		elem->str = ft_strjoin(elem->str, width);
	else
		elem->str = ft_strjoin(width, elem->str);
	free(width);
	free(tmp);
}

char	*str_precision(char *str, int len)
{
	char	*precision;

	precision = ft_substr(str, 0, len);
	if (!precision)
		return (NULL);
	return (precision);
}

char	*int_precision(char *str, int len)
{
	char	*precision;
	char	*tmp;

	precision = (char *)malloc(sizeof(char) * (len + 2));
	if (!precision)
	{
		free(str);
		return (NULL);
	}
	precision[0] = '.';
	precision[len + 1] = '\0';
	tmp = str;
	str = ft_strjoin(str, precision);
	free(tmp);
	free(precision);
	return (str);
}

void	handle_precision(t_token *elem)
{
	char	*tmp;

	if (elem->f.precision <= 0)
		return ;
	tmp = elem->str;
	if (ft_strchr("diu", elem->specifier))
		elem->str = int_precision(elem->str, elem->f.precision);
	else if (ft_strchr("s", elem->specifier))
		elem->str = str_precision(elem->str, elem->f.precision);
	free(tmp);
}
