/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:02:46 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/04/05 15:46:34 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	int				x;

	uc = (unsigned char)c;
	x = 0;
	while (s[x])
	{
		x++;
	}
	if (uc == '\0')
		return ((char *)s + x);
	while (x--)
	{
		if (s[x] == uc)
			return (((char *)s) + x);
	}
	if (x <= 0)
		return (NULL);
	return (((char *)s) + x);
}
