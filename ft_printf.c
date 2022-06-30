#include "ft_printf.h"
#include <stdio.h>

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
		else
		{
			str++;
			if (*str == 'c')
			      bprint += ft_putchar(va_arg(ptr, int));
			if (*str == 's')
				bprint += ft_putstr(va_arg(ptr, char*));	
			if (*str == 'p')
				bprint += ft_itoa(va_arg(ptr, unsigned int));	
		} str++;	
	}
	return (bprint);
}

int	main(void)
{
	char c = 'a';
	char str[] = "Uma string qualquer";
	printf("Retorno função ft_printf: %i\n", ft_printf("Teste sem args extras\nTeste com char %c OK\nTeste com str %s OK\nTeste com pointer %p OK\n", c, str, &c));
	printf("Retorno função original : %i\n", printf("Teste sem args extras\nTeste com char %c OK\nTeste com str %s OK\nTeste com pointer %p OK\n", c, str, &c));
}	
//cspdiuxX%
