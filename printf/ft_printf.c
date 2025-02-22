/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:15:37 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/11 00:08:44 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		total_len;
	va_list	args;

	total_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total_len += ft_mod(format, args);
		}
		else
			total_len += ft_putcharpf(*format);
		format++;
	}
	va_end(args);
	return (total_len);
}
