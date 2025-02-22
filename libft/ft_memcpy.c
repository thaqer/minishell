/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:03:52 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/03 09:02:55 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	x;
	char	*a;
	char	*b;

	a = (char *)dest;
	b = (char *)src;
	x = 0;
	if (!a && !b)
		return (0);
	while (x < n)
	{
		a[x] = b[x];
		x++;
	}
	return (dest);
}
