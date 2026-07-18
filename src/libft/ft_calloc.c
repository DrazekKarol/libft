/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:16:43 by kdrazek           #+#    #+#             */
/*   Updated: 2025/01/09 14:54:09 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t			t;
	void			*ptr;
	unsigned char	*b;
	size_t			i;

	i = 0;
	if (n == 0 || size == 0)
		return (malloc(0));
	t = n * size;
	if (t / n != size)
		return (NULL);
	ptr = malloc(t);
	if (ptr == NULL)
		return (NULL);
	b = (unsigned char *)ptr;
	while (i < t)
	{
		b[i] = 0;
		i++;
	}
	return (ptr);
}
