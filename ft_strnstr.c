/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:13:39 by kdrazek           #+#    #+#             */
/*   Updated: 2025/01/09 15:00:13 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)big;
	if (!little[0] || (!str && 0 == len))
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[j + i] == little[j] && str[i + j])
			j++;
		if ((j + i) > len)
			return (NULL);
		if (!little[j])
			return (&str[i]);
		i++;
	}
	return (NULL);
}
