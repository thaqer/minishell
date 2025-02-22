/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrpf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:42:50 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/10 12:34:26 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrpf(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
		write(1, &str[len++], 1);
	return (len);
}
