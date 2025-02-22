/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:16:26 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/04 19:14:47 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*a;
	unsigned char		*b;

	a = (const unsigned char *)src;
	b = (unsigned char *)dest;
	if (!a && !b)
		return (NULL);
	if (a > b)
	{
		while (n--)
			*b++ = *a++;
	}
	else
	{
		b += n;
		a += n;
		while (n--)
			*--b = *--a;
	}
	return (dest);
}
