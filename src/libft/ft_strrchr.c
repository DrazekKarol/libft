/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:50:42 by kdrazek           #+#    #+#             */
/*   Updated: 2025/01/09 15:16:04 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	my_c;
	int		len;

	len = ft_strlen(s);
	my_c = (const char)c;
	while (len)
	{
		if (s[len] == my_c)
			return ((char *)&s[len]);
		len--;
	}
	if (s[0] == my_c)
		return ((char *)&s[len]);
	return (NULL);
}
