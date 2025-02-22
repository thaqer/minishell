/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:17:04 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/01 08:18:09 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		x;
	int		len;

	x = 0;
	len = ft_strlen(s);
	dest = (char *)malloc(len * sizeof(char) + 1);
	if (!dest)
		return (0);
	while (s[x])
	{
		dest[x] = s[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

// int		main(void)
// {
// 	char	*str;
// 	char	*allocated;

// 	str = "Hello World with malloc()";
// 	printf("original  : base  : $%s$ @ %p\n", str, str);
// 	allocated = strdup(str);
// 	printf("copied    : alloc : $%s$ @ %p\n", allocated, allocated);
// 	allocated = ft_strdup(str);
// 	printf("ft_copied : alloc : $%s$ @ %p\n", allocated, allocated);
// }