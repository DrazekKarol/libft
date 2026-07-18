/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrazek <kdrazek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:36:36 by kdrazek           #+#    #+#             */
/*   Updated: 2025/02/03 12:02:07 by kdrazek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

int	ft_print_char(int c);
int	ft_print_uni(unsigned int n);
int	ft_printf(const char *str, ...);
int	ft_print_hex(unsigned int j, char format);
int	ft_printnumber(int nb, int i);
int	ft_printstring(char *s);
#endif