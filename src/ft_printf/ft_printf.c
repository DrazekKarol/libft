/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:45:27 by kdrazek           #+#    #+#             */
/*   Updated: 2025/02/03 12:02:04 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printp(unsigned long long i)
{
	int		j;
	char	*x;

	x = "0123456789abcdef";
	j = 0;
	if (i >= 16)
	{
		j += ft_printp(i / 16);
		i = i % 16;
	}
	j += write(1, &x[i], 1);
	return (j);
}

int	ft_printpointer(unsigned long long p)
{
	int	i;

	i = 0;
	if (p == 0)
	{
		i += write(1, "(nil)", 5);
		return (i);
	}
	else
	{
		i += write(1, "0x", 2);
		i += ft_printp(p);
	}
	return (i);
}

int	ft_format(va_list args, char *format)
{
	int	print_lenght;

	print_lenght = 0;
	if (*format == 'c')
		print_lenght += ft_print_char(va_arg(args, int));
	else if (*format == 'd' || *format == 'i')
		print_lenght += ft_printnumber(va_arg(args, int), 0);
	else if (*format == 's')
		print_lenght += ft_printstring(va_arg(args, char *));
	else if (*format == 'p')
		print_lenght += ft_printpointer(va_arg(args, long long));
	else if (*format == 'u')
		print_lenght += ft_print_uni(va_arg(args, unsigned int));
	else if (*format == 'x')
		print_lenght += ft_print_hex(va_arg(args, unsigned int), 'x');
	else if (*format == 'X')
		print_lenght += ft_print_hex(va_arg(args, int), 'X');
	else if (*format == '%')
		print_lenght += ft_print_char('%');
	return (print_lenght);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_lenght;

	if (!format)
		return (0);
	print_lenght = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			print_lenght += ft_format(args, (char *)++format);
		}
		else
			print_lenght += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (print_lenght);
}
