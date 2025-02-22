/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:18:18 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/01 11:18:53 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	char	*str;

	x = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
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

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		x;
	int		len;

	x = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	dest = (char *)malloc(len * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (s[x])
	{
		dest[x] = s[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	x;

	if (!s)
		return (0);
	x = 0;
	while (s[x])
		x++;
	return (x);
}
