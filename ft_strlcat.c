/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:25:25 by kdrazek           #+#    #+#             */
/*   Updated: 2025/01/09 15:09:01 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	s;
	size_t	d;

	s = ft_strlen(src);
	if (!dest && size == 0)
		return (s);
	j = ft_strlen(dest);
	d = j;
	if (size <= d)
		return (size + s);
	i = 0;
	while (src[i] && j < size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return (s + d);
}
