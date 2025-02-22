/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:43:44 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/10 15:02:39 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long num, char *base, int base_len)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len += ft_putcharpf('-');
		num = -num;
	}
	if (num >= base_len)
		len += ft_putnbr_base(num / base_len, base, base_len);
	len += ft_putcharpf(base[num % base_len]);
	return (len);
}
