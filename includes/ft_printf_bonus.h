/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:23:35 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/11 10:54:47 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

# define SPECS "csdiuxXp%"

# define FLAGS "-+0 #"
# define FLAG_MINUS 0x01
# define FLAG_PLUS  0x02
# define FLAG_ZERO  0x04
# define FLAG_SPACE 0x08
# define FLAG_HASH  0x10

# define TRUE 1
# define FALSE 0
# define T_TEXT 2
# define T_SPEC 3

typedef struct s_flags
{
	int	flags;
	int	precision;
	int	width;
}	t_flags;

typedef union u_spec_data
{
	int				i;
	char			c;
	unsigned int	u;
	char			*str;
	void			*ptr;
}	t_spec_data;

typedef struct s_fmt_token
{
	char				specifier;
	char				*str;
	int					len;
	int					type;
	t_spec_data			data;
	t_flags				f;
	struct s_fmt_token	*next;
}	t_token;

typedef struct s_spec
{
	char	specifier;
	char	*(*eval)(const char *, t_spec_data);
}	t_spec;

/* main function */
int		ft_printf(const char *fmt, ...);

/* Parser */
void	parse_fmt(const char *fmt, t_token **head);

/* tokenizer */
int		ft_tokensize(t_token *head);
void	ft_tokenadd_back(t_token **head, t_token *new);
t_token	*ft_tokenew(int type);
t_token	*ft_tokenlast(t_token *head);
void	ft_tokenclear(t_token **head, void (*del)(void *));
void	ft_tokendelone(t_token *elem, void (*del)(void *));

/* Helper functions.*/
int		ft_strchar(char *str, int c);
char	*ft_putptr(uintptr_t ptr);
size_t	ft_num_len(unsigned long nb, size_t base);
char	*ft_print_hex(char *base, unsigned int num);
int		ft_print_str(char *str, int length);

/* specifier's functions*/
char	*eval_char(const char *token, t_spec_data data);
char	*eval_str(const char *token, t_spec_data data);
char	*eval_int(const char *token, t_spec_data data);
char	*eval_uint(const char *token, t_spec_data data);
char	*eval_ptr(const char *token, t_spec_data data);
char	*eval_hex(const char *token, t_spec_data data);
char	*eval_HEX(const char *token, t_spec_data data);
char	*eval_percent(const char *token, t_spec_data data);
char	*eval_spec(char sp, t_spec_data data, t_spec *specs);
t_token	*eval_fmt(t_token **head, t_spec *specs);

#endif
