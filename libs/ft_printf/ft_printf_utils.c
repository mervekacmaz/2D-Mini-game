/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:50:38 by mkacmaz           #+#    #+#             */
/*   Updated: 2022/04/10 13:57:04 by mkacmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int nb)
{
	long	n;
	int		len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += print_nbr(n / 10);
		len += print_nbr(n % 10);
	}
	if (n < 10)
		len += print_char(n + 48);
	return (len);
}

int	print_unsigned_integer(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += print_unsigned_integer(nb / 10);
		len += print_unsigned_integer(nb % 10);
	}
	if (nb < 10)
		len += print_char(nb + 48);
	return (len);
}

int	print_hex(unsigned int nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_hex(nb / 16, s);
		len += print_hex(nb % 16, s);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_char(nb + 48);
		else
		{
			if (s == 1)
				len += print_char(nb + 87);
			else
				len += print_char(nb + 55);
		}
	}
	return (len);
}

int	print_ptr(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_ptr(nb / 16);
		len += print_ptr(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_char(nb + 48);
		else
			len += print_char(nb + 87);
	}
	return (len);
}
