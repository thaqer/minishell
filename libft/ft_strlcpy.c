/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:47:11 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/03 09:02:55 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;

	x = 0;
	if (size == 0)
	{
		while (src[x])
			x++;
		return (x);
	}
	while ((src[x]) && x < (size - 1))
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	x = 0;
	while (src[x])
		x++;
	return (x);
}
/*
int	main(void)
{
		char c[20];
		printf("%zu\n",ft_strlcpy(c,"farahhhh",2));
		printf("%zu",strlcpy(c,"farahhhh",2));

	return (0);
}*/