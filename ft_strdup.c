/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:26:58 by kdrazek           #+#    #+#             */
/*   Updated: 2025/01/09 15:08:27 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*k;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i])
		i++;
	k = malloc(i + 1);
	if (k == NULL)
		return (NULL);
	while (j < i)
	{
		k[j] = s[j];
		j++;
	}
	k[j] = '\0';
	return ((char *)k);
}
