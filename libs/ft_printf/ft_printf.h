/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:50:48 by mkacmaz           #+#    #+#             */
/*   Updated: 2022/04/10 13:56:24 by mkacmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	print_char(char c);
int	ft_check(char c, va_list safe);
int	print_nbr(int nb);
int	print_str(char	*str);
int	print_ptr(unsigned long int n);
int	print_unsigned_integer(unsigned int nb);
int	print_hex(unsigned int nb, int s);

#endif
