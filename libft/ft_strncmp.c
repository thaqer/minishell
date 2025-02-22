/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:44:47 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/03 09:02:55 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			x;
	unsigned char	a;
	unsigned char	b;

	x = 0;
	while ((s1[x] != '\0' || s2[x] != '\0') && x < n)
	{
		a = (unsigned char)s1[x];
		b = (unsigned char)s2[x];
		if (a != b)
			return (a - b);
		x++;
	}
	return (0);
}

/*
int	main(void)
{
	char s1[] = "thaeri";
	char s2[] = "thaere";
	int s = ft_strncmp(s1,s2,5);
	printf("%d", s);
}*/
