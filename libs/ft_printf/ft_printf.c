/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:50:20 by mkacmaz           #+#    #+#             */
/*   Updated: 2022/04/10 13:53:26 by mkacmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	print_str(char	*str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	ft_check(char c, va_list safe)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += print_char(va_arg(safe, int)); //holds an int, returns the lenght
	if (c == 'd' || c == 'i')
		len += print_nbr(va_arg(safe, int));
	if (c == 's')
		len += print_str(va_arg(safe, char *));
	if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += print_ptr(va_arg(safe, unsigned long int));
	}
	if (c == 'u')
		len += print_unsigned_integer(va_arg(safe, unsigned int));
	if (c == 'x')
		len += print_hex(va_arg(safe, unsigned int), 1);
	if (c == 'X')
		len += print_hex(va_arg(safe, unsigned int), 2);
	if (c == '%')
		len += print_char('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	int		i;
	va_list	safe;

	len = 0;
	i = 0;
	va_start(safe, s);
	while (s[i])
	{
		if (s[i] != '%')
			len += write(1, &s[i], 1);
		if (s[i] == '%')
		{
			len += ft_check(s[i + 1], safe); //%'den sonra gelen işareti alıyor o yüzden + 1
			i++;
		}
		i++;
	}
	va_end(safe);
	return (len);
}
