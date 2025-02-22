/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:40:33 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/10 23:57:18 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_baseu(size_t num, char *base, size_t base_len)
{
	int	len;

	len = 0;
	if (num >= base_len)
		len += ft_putnbr_base(num / base_len, base, base_len);
	len += ft_putcharpf(base[num % base_len]);
	return (len);
}

int	ft_putpoin(void *args)
{
	int	len;

	len = 0;
	if (!args)
		len += ft_putstrpf("(nil)");
	else
	{
		len += ft_putstrpf("0x");
		len += ft_putnbr_baseu((size_t)args, "0123456789abcdef", 16);
	}
	return (len);
}
