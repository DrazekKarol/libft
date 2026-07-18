/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:11:22 by kdrazek           #+#    #+#             */
/*   Updated: 2025/01/09 15:21:06 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	const unsigned char	*s;
	unsigned char		c;

	s = (const unsigned char *)ptr;
	c = (unsigned char)ch;
	while (count--)
	{
		if (*s == c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
