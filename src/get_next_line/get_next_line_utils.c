/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:29:38 by kdrazek           #+#    #+#             */
/*   Updated: 2025/03/06 14:57:06 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_gnl_list *node)
{
	int	i;

	if (!node)
		return (0);
	while (node)
	{
		i = 0;
		while (node->str_buf[i])
		{
			if (node->str_buf[i] == '\n')
				return (1);
			i++;
		}
		node = node->next;
	}
	return (0);
}

t_gnl_list	*allocate_node(void)
{
	t_gnl_list	*new_node;

	new_node = malloc(sizeof(t_gnl_list));
	if (!new_node)
		return (NULL);
	new_node->str_buf = malloc(BUFFER_SIZE + 1);
	if (!new_node->str_buf)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

void	free_list(t_gnl_list **list)
{
	t_gnl_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
}

void	append_node(t_gnl_list **list, t_gnl_list **last, t_gnl_list *node)
{
	if (!*list)
		*list = node;
	else
		(*last)->next = node;
	*last = node;
}

void	generate_line(char **line, t_gnl_list *list)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			(*line)[j] = list->str_buf[i];
			j++;
			if (list->str_buf[i] == '\n')
				break ;
			i++;
		}
		list = list->next;
	}
	(*line)[j] = '\0';
}
