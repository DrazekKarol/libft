/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:14:55 by kdrazek           #+#    #+#             */
/*   Updated: 2025/02/03 12:02:10 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnumber(int nb, int i)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_print_char('-');
		nb = -nb;
		++i;
	}
	if (nb >= 10)
	{
		i = ft_printnumber(nb / 10, i);
		nb = nb % 10;
	}
	nb = nb + '0';
	ft_print_char(nb);
	i++;
	return (i);
}
