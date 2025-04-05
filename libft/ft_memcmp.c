/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:24:39 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/04/05 15:45:48 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				x;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	a = s1;
	b = s2;
	x = 0;
	while (x < n)
	{
		if (a[x] != b[x])
			return (a[x] - b[x]);
		x++;
	}
	return (0);
}