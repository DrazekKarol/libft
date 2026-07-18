/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:04:42 by kdrazek           #+#    #+#             */
/*   Updated: 2025/03/06 14:57:46 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_gnl_list
{
	char				*str_buf;
	struct s_gnl_list	*next;
}	t_gnl_list;

char		*get_next_line(int fd);

/* Funkcje pomocnicze listowe */
int			found_newline(t_gnl_list *node);
void		free_list(t_gnl_list **list);
t_gnl_list	*allocate_node(void);
void		append_node(t_gnl_list **list, t_gnl_list **last, t_gnl_list *node);
void		generate_line(char **line, t_gnl_list *list);

#endif
