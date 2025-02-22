/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:25:17 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/03 09:04:18 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*c;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	c = ft_calloc(len + 1, sizeof(char));
	if (!c)
		return (NULL);
	i = 0;
	while (i < len)
	{
		c[i] = f(i, s[i]);
		i++;
	}
	return (c);
}
