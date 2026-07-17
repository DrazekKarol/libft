/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:42:42 by kdrazek           #+#    #+#             */
/*   Updated: 2025/01/09 15:26:39 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	j;
	size_t	i;

	if (!s)
		return (0);
	j = ft_strlen(s);
	if (start >= j)
		return (ft_strdup(""));
	if (start + len > j)
		i = j - start;
	else
		i = len;
	sub = (char *)malloc((i + 1) * sizeof(char));
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, i + 1);
	return (sub);
}
