#include "ft_printf.h"

int	putunsigned(int base, unsigned int n, char c)
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

#include <stdio.h>
int	main(void)
{
	char c = 'a';
	char str[] = "Uma string qualquer";
	char *nptr = 0;
	printf("Retorno função ft_printf: %i\n", ft_printf("Teste sem args extras\nTeste com char %c OK\nTeste com str %s OK\nTeste com pointer %p OK\nTeste com pointer NULL %p OK\nTeste com %% seguidos na frase OK\nTeste com decimal %d OK\nTeste com inteiro %i OK\nTeste com decimal(u) %u OK\nTeste com hexa(x) %x OK\nTeste com hexa(X) %X OK\n", c, str, &c, nptr, 42, -42, -5, 16, 736));
	printf("Retorno função original : %i\n", printf("Teste sem args extras\nTeste com char %c OK\nTeste com str %s OK\nTeste com pointer %p OK\nTeste com pointer NULL %p OK\nTeste com %% seguidos na frase OK\nTeste com decimal %d OK\nTeste com inteiro %i OK\nTeste com decimal(u) %u OK\nTeste com hexa(x) %x OK\nTeste com hexa(X) %X OK\n", c, str, &c, nptr, 42, -42, -5, 16, 736));
}