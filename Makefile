# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 12:50:29 by kdrazek           #+#    #+#              #
#    Updated: 2025/01/09 14:34:20 by kdrazek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBH = libft.h
CC = gcc
FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c \
ft_toupper.c ft_strlcpy.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

CFLAG = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

OBJ = $(FILES:.c=.o)

BOBJ = $(BFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBH)
		$(CC) $(CFLAG) -c $(FILES) $(BFILES) $(LIBH)
		$(AR) $(NAME) $(OBJ)
		
bonus: $(NAME) $(BOBJ)
		$(AR) $(NAME) $(BOBJ)		
clean:
		$(RM) $(OBJ) $(BOBJ)
fclean: clean
		$(RM) $(NAME) $(bonus)
re: fclean all

.PHONY: all bonus clean fclean re
