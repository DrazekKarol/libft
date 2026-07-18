/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:13:05 by kdrazek           #+#    #+#             */
/*   Updated: 2025/01/09 15:22:31 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	char			l;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	l = 1;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		l = -1;
		d += n - 1;
		s += n - 1;
	}
	while (i < n)
	{
		*d = *s;
		d += l;
		s += l;
		i++;
	}
	return (dest);
}
