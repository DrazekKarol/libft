/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:16:29 by kdrazek           #+#    #+#             */
/*   Updated: 2025/03/06 14:57:46 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_to_list(t_gnl_list **list, int fd)
{
	t_gnl_list	*node;
	t_gnl_list	*last;
	int			b;

	last = *list;
	while (last && last->next)
		last = last->next;
	while (!found_newline(last))
	{
		node = allocate_node();
		if (node)
			b = read(fd, node->str_buf, BUFFER_SIZE);
		if (!node || b <= 0)
		{
			if (!node || b < 0)
				free_list(list);
			if (node)
				free_list(&node);
			return ;
		}
		node->str_buf[b] = '\0';
		append_node(list, &last, node);
	}
}

static char	*extract_line(t_gnl_list *list)
{
	int			i;
	int			len;
	char		*line;
	t_gnl_list	*tmp;

	len = 0;
	tmp = list;
	while (tmp)
	{
		i = 0;
		while (tmp->str_buf[i])
		{
			len++;
			if (tmp->str_buf[i] == '\n')
				break ;
			i++;
		}
		tmp = tmp->next;
	}
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	generate_line(&line, list);
	return (line);
}

static void	clean_node(t_gnl_list **list, t_gnl_list *clean, char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	while (buf[i])
	{
		clean->str_buf[j] = buf[i];
		i++;
		j++;
	}
	clean->str_buf[j] = '\0';
	free_list(list);
	if (clean->str_buf[0])
		*list = clean;
	else
	{
		free(clean->str_buf);
		free(clean);
	}
}

static void	prepare_next_call(t_gnl_list **list)
{
	t_gnl_list	*last;
	t_gnl_list	*clean;

	if (!*list)
		return ;
	last = *list;
	while (last->next)
		last = last->next;
	if (!last->str_buf)
		return (free_list(list));
	clean = allocate_node();
	if (!clean)
	{
		free_list(list);
		return ;
	}
	clean_node(list, clean, last->str_buf);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*list;
	char				*line;

	if (fd == -1)
	{
		free_list(&list);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free_list(&list);
		return (NULL);
	}
	read_to_list(&list, fd);
	if (!list)
		return (NULL);
	line = extract_line(list);
	if (line == (char *)1)
		line = NULL;
	prepare_next_call(&list);
	return (line);
}
