#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int	bprint;

	va_start(ptr, str);
	while(*str)
	{
		if (*str != '%')
			bprint = ft_putchar(*str);
		str++;
	}
	return (bprint);
}

int	main(void)
{
	ft_printf("Teste sem args extras");
}
