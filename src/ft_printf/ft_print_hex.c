/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:05:31 by kdrazek           #+#    #+#             */
/*   Updated: 2025/01/31 16:07:03 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(char *x, unsigned int i)
{
	int	j;

	j = 0;
	if (i >= 16)
	{
		j += ft_hex(x, i / 16);
		i = i % 16;
	}
	j += write(1, &x[i], 1);
	return (j);
}

int	ft_print_hex(unsigned int i, char format)
{
	char	*x;
	char	*xx;
	int		j;

	j = 0;
	x = "0123456789abcdef";
	xx = "0123456789ABCDEF";
	if (format == 'x')
		j = ft_hex(x, i);
	else if (format == 'X')
		j = ft_hex(xx, i);
	return (j);
}
