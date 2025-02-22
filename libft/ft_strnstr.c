/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:00:44 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/01 17:56:21 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[x] && x < len)
	{
		y = 0;
		while (little[y] && big[x + y] && (x + y) < len
			&& big[x + y] == little[y])
			y++;
		if (little[y] == '\0')
			return ((char *)(big + x));
		x++;
	}
	return (NULL);
}

// int main()
// {
// 	char    str1[] = "hello world";
//     char    str2[] = "e";

//     printf(" %s\n", str1);
//     printf("%s\n", str2);
//     printf("%s\n", ft_strnstr(str1, str2, 10));

//     return (0);
// }
