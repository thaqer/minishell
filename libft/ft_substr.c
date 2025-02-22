/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:17:45 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/01 08:18:09 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	char	*str;

	x = 0;
	if (start >= ft_strlen(s))
		return (strdup(""));
	if (len > (strlen(s) - start))
		len = strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start + x] && x < len)
	{
		str[x] = s[start + x];
		x++;
	}
	str[x] = '\0';
	return (str);
}
