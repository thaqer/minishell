/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:24:39 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/04 08:58:03 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				x;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	a = s1;
	b = s2;
	x = 0;
	while (x < n)
	{
		if (a[x] != b[x])
			return (a[x] - b[x]);
		x++;
	}
	return (0);
}

// int main() {
//     const char str1[] = "Hello, World!";
//     const char str2[] = "Hello, World!";
//     const char str3[] = "Hello, C Programmers!";
//     int result1 = memcmp(str1, str2, sizeof(str1));
//     int result2 = memcmp(str1, str3, sizeof(str1));
//     int result3 = memcmp(str2, str3, sizeof(str2));

//     printf("Comparison of str1 and str2: %d\n", result1);
//     printf("Comparison of str1 and str3: %d\n", result2);
//     printf("Comparison of str2 and str3: %d\n", result3);
// }
