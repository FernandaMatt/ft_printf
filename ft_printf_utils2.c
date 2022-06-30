/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:40:06 by fcaetano          #+#    #+#             */
/*   Updated: 2022/06/30 15:42:03 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptr_rec(unsigned long n, char t)
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
		return (write(1, "0x0", 3));
	return (ft_putstr("0x") + putptr_rec(n, t));
}

int	putdec_rec(int n)
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
	int	bprint;

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

int	putunsigned(unsigned int base, unsigned int n, char c)
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

/* int	putu(unsigned int n)
{
	int		size;

	size = 0;
	if (n >= 10)
		size += putu(n / 10);
	size += ft_putchar((n % 10) + '0');
	return (size);
} */
