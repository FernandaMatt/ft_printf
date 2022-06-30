/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:30:38 by fcaetano          #+#    #+#             */
/*   Updated: 2022/06/30 15:45:11 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_specifiers(va_list ptr, char specifier)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(ptr, char *)));
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
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		bprint;

	va_start(ptr, str);
	bprint = 0;
	while (*str)
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
