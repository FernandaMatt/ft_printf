/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsigned.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:59:58 by fcaetano          #+#    #+#             */
/*   Updated: 2022/06/02 15:30:36 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// ARRUMAR HEADER EM TODOS OS ARQUIVOS!!!!

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_strlen(const char *str);
int	putunsigned(int base, unsigned int n, char t);

#include <stdlib.h>

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

int	putptr_rec(unsigned long n, char t) //testar com NULL
{
	int		size;

	size = 0;
	
	if (n >= 16)
		size += putptr_rec(n / 16, t);
	if ((n % 16) <= 9)
		size += ft_putchar((n % 16) + '0');
	else if (t == 'x')
		size += ft_putchar((n % 16) + 87);
	else if (t == 'X')
		size += ft_putchar((n % 16) + 55);
	return (size);
}

int	putptr(unsigned long n, char t)
{	
	if (n == 0)
		return (write(1, "(null)", 6));
	return (ft_putstr("0x") + putptr_rec(n, t));
}

int	putdec_rec(int n) //testar com NULL
{
	int		size;

	size = 0;

	if (n >= 10)
		size += putdec_rec(n / 10);
	size += ft_putchar((n % 10) + '0');
	return (size);
}

int	putdec(int n)
{
	int bprint;

	bprint = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		bprint += write(1, "-", 1);
		n *= -1;
	}
	bprint += putdec_rec(n);
	return (bprint);
}

/* int	putu(unsigned int n)
{
	int		size;

	size = 0;
	if (n >= 10)
		size += putu(n / 10);
	size += ft_putchar((n % 10) + '0');
	return (size);
} */

int	putunsigned(int base, unsigned int n, char c) //testar com NULL
{
	int	size;

	size = 0;

	if (n >= base)
		size += putunsigned(base, (n / base), c);
	if ((n % base) <= 9)
		size += ft_putchar((n % base) + '0');
	else if (c == 'x')
		size += ft_putchar((n % 16) + 87);
	else if (c == 'X')
		size += ft_putchar((n % 16) + 55);
	return (size);
}

int print_specifiers(va_list ptr, char specifier)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(ptr, char*)));	
	if (specifier == 'p')
		return (putptr(va_arg(ptr, unsigned long), 'x'));
	if (specifier == '%')
		return (ft_putchar('%'));
	if (specifier == 'd' || specifier == 'i')
		return (putdec(va_arg(ptr, int)));
	if (specifier == 'u')
		return (putunsigned(10, va_arg(ptr, unsigned int), 0));
	if (specifier == 'x')
		return (putunsigned(16, va_arg(ptr, unsigned int), 'x'));
	if (specifier == 'X')
		return (putunsigned(16, va_arg(ptr, unsigned int), 'X'));
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int	bprint;

	va_start(ptr, str);
	bprint = 0;	
	while(*str)
	{
		if (*str != '%')
			bprint += ft_putchar(*str);
		else if (ft_strchr("cspdiuxX%", str[1]))
		{
			str++;
			bprint += print_specifiers(ptr, *str);
		}
		else
			bprint += ft_putchar(*str); //caso de % solto na frase, ele só printa o %, pode ser assim ? -> função original dá segfault, o que fazer ??? segfault é comportamento indefinido, então foda-se ???
		str++;
	}
	return (bprint);
}

int	main(void)
{
	char c = 'a';
	char str[] = "Uma string qualquer";
	char *nptr = 0;
	printf("Retorno função ft_printf: %i\n", ft_printf("Teste sem args extras\nTeste com char %c OK\nTeste com str %s OK\nTeste com pointer %p OK\nTeste com pointer NULL %p OK\nTeste com %% seguidos na frase OK\nTeste com decimal %d OK\nTeste com inteiro %i OK\nTeste com decimal(u) %u OK\nTeste com hexa(x) %x OK\nTeste com hexa(X) %X OK\n", c, str, &c, nptr, 42, -42, -5, 16, 736));
	printf("Retorno função original : %i\n", printf("Teste sem args extras\nTeste com char %c OK\nTeste com str %s OK\nTeste com pointer %p OK\nTeste com pointer NULL %p OK\nTeste com %% seguidos na frase OK\nTeste com decimal %d OK\nTeste com inteiro %i OK\nTeste com decimal(u) %u OK\nTeste com hexa(x) %x OK\nTeste com hexa(X) %X OK\n", c, str, &c, nptr, 42, -42, -5, 16, 736));
}
