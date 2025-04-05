/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:00:44 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/04/05 15:46:28 by tbaniatt         ###   ########.fr       */
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
