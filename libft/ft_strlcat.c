/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:47:35 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/03 09:00:26 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	i;

	x = 0;
	y = 0;
	while (dest[x])
	{
		x++;
	}
	while (src[y])
	{
		y++;
	}
	if (x >= size)
		return (size + y);
	i = 0;
	while (src[i] != '\0' && (x + i) < (size - 1))
	{
		dest[x + i] = src[i];
		i++;
	}
	dest[x + i] = '\0';
	return (x + y);
}
/*
int	main(void)
{
		char s[] = "farah";
		char d[100] = "jehad";
		//   printf("%zu\n", ft_strlcat(d,s,3));
		//   printf("%zu\n", strlcat(d,s,3));

		// printf("%zu\n", ft_strlcat(d,s,4));
		printf("%zu\n", strlcat(d,s,4));

		//strlcat(d,s,3);
		//printf("%s\n", strlcat(d,s,3));
}*/
/*
int	main(void) {
	char dest1[30] = "Hello, ";
	char dest2[30] = "Hello, ";
	const char *src = "World!";


	// Using ft_strlcat to concatenate the strings
	size_t result1 = ft_strlcat(dest1, src, 7);

	// Using the standard strlcat function for comparison
	size_t result2 = strlcat(dest2, src, 7);

	// Output the results
	printf("ft_strlcat:\n");
	printf("Result length: %zu\n", result1);
	printf("Destination: %s\n", dest1);

	printf("\nstrlcat:\n");
	printf("Result length: %zu\n", result2);
	printf("Destination: %s\n", dest2);

}*/