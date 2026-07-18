/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uni.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:12:01 by kdrazek           #+#    #+#             */
/*   Updated: 2025/02/03 12:02:01 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uni(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i = ft_printnumber(n / 10, i);
		n = n % 10;
	}
	n = n + '0';
	ft_print_char(n);
	i++;
	return (i);
}
