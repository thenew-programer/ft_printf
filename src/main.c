#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>

char* substr(char* str, int pos, int len) {
    char* substr = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        substr[i] = str[pos + i];
    }
    substr[i] = '\0'; // null-terminate the substring
    return substr;
}

int	ft_parse(char *fmt)
{
	int		i;
	int		start;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen(fmt);
	while (i < len)
	{
		if (fmt[i] == '%' && i < len)
		{
			tmp = substr(fmt, i, 2);
			printf("%s\n", tmp);
			free(tmp);
			i += 2;
		}
		else
		{
			start = i;
			while (fmt[i] != '%' && i < len)
				i++;
			tmp = substr(fmt, start, i - start);
			printf("%s\n", tmp);
			free(tmp);
		}
	}
	return (start);
}

int main()
{
	ft_parse("hello world %s how %  are u %%%c great %");
	return (0);
}
