/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:54:09 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/21 19:22:07 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;
	unsigned char		uc;
	size_t				x;

	a = (const unsigned char *)s;
	uc = (unsigned char)c;
	x = 0;
	while (x < n)
	{
		if (a[x] == uc)
			return ((void *)(a + x));
		x++;
	}
	return (NULL);
}
