/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:17:38 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/03 09:02:55 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*a;
	char	*b;

	a = (char *)s1;
	b = (char *)s1 + ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (*a && ft_strchr(set, *a))
		a++;
	while (b > a && ft_strchr(set, *b))
		b--;
	len = b - a + 1;
	return (ft_substr(a, 0, len));
}
// how can i use ft_strrchr????
