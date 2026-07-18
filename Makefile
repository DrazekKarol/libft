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

NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I$(INC_DIR)
AR          = ar rcs
RM          = rm -rf

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = inc

LIBFT_DIR   = $(SRC_DIR)/libft
PRINTF_DIR  = $(SRC_DIR)/ft_printf
GNL_DIR     = $(SRC_DIR)/get_next_line

LIBFT_SRC   = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
		ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c \
		ft_toupper.c ft_strlcpy.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	 	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
PRINTF_SRC  = ft_printf.c ft_print_char.c ft_print_uni.c \
	      ft_print_hex.c ft_printnumber.c ft_printstring.c
GNL_SRC     = get_next_line.c get_next_line_utils.c

# Generowanie pełnych ścieżek do plików źródłowych
SRCS        = $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC)) \
              $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRC)) \
              $(addprefix $(GNL_DIR)/, $(GNL_SRC))

# Mapowanie ścieżek źródłowych na pliki obiektowe
OBJS        = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Reguły główne
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Konsolidacja archiwum statycznego $(NAME)..."
	@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Czyszczenie plików obiektowych (.o)..."
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "Usuwanie biblioteki $(NAME)..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
