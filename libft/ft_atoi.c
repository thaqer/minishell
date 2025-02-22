/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:05:16 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/25 23:21:42 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	x;
	int	ne;
	int	n;

	x = 0;
	n = 0;
	ne = 1;
	while (nptr[x] == 32 || (nptr[x] >= 9 && nptr[x] <= 13))
		x++;
	if (nptr[x] == '+' || nptr[x] == '-')
	{
		if (nptr[x] == '-')
			ne = ne * -1;
		x++;
	}
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		n = (n * 10) + (nptr[x] - '0');
		x++;
	}
	return (n * ne);
}
