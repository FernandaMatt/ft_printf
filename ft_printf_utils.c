#include "ft_printf.h"

int	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return (1);
		s++;
	}
	if ((char)c == *s)
		return (1);
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int    ft_putstr(char *s)
{
	if (s == NULL)
		return (0);
	write(0, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_strlen(const char *str)
{
	int	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}