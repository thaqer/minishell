/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:44:49 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/04 19:52:43 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	int				x;

	uc = (unsigned char)c;
	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == uc)
			return ((char *)s + x);
		x++;
	}
	if (uc != '\0')
		return (NULL);
	return ((char *)s + x);
}
