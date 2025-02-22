/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:46:22 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/11 00:07:50 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbrpf(int num)
{
	return (ft_putnbr_base(num, "0123456789", 10));
}

static int	ft_putnbr_unsigned(unsigned int num)
{
	return (ft_putnbr_base(num, "0123456789", 10));
}

static int	ft_putnbr_hex(unsigned int num, char format)
{
	if (format == 'X')
		return (ft_putnbr_base(num, "0123456789ABCDEF", 16));
	else
		return (ft_putnbr_base(num, "0123456789abcdef", 16));
	return (0);
}

int	ft_mod(const char *str, va_list args)
{
	int	len;

	len = 0;
	if (*str == 'd' || *str == 'i')
		len += ft_putnbrpf(va_arg(args, int));
	else if (*str == 'p')
		len += ft_putpoin(va_arg(args, void *));
	else if (*str == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*str == 'x' || *str == 'X')
		len += ft_putnbr_hex(va_arg(args, unsigned int), *str);
	else if (*str == 's')
		len += ft_putstrpf(va_arg(args, char *));
	else if (*str == 'c')
		len += ft_putcharpf(va_arg(args, int));
	else if (*str == '%')
		len += ft_putcharpf('%');
	return (len);
}
