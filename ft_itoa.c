/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:39:27 by kdrazek           #+#    #+#             */
/*   Updated: 2025/01/09 14:47:43 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_change(char *s, unsigned int number, int len)
{
	while (number > 0)
	{
		s[len] = '0' + (number % 10);
		len--;
		number = number / 10;
	}
	return (s);
}

static int	ft_len(int i)
{
	int	j;

	j = 0;
	if (i <= 0)
		j++;
	while (i != 0)
	{
		j++;
		i = i / 10;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	len;
	int				num;
	int				sign;

	sign = 1;
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		sign *= (-1);
		num = n * (-1);
		s[0] = '-';
	}
	else
		num = n;
	s = ft_change(s, num, len);
	return (s);
}
