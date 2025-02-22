/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:17:16 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/25 23:23:03 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	x;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!str)
		return (NULL);
	x = 0;
	while (x < l1)
	{
		str[x] = s1[x];
		x++;
	}
	while (x < (l1 + l2))
	{
		str[x] = *s2++;
		x++;
	}
	str[x] = '\0';
	return (str);
}
