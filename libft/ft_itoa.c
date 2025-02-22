/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:15:40 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/04 17:10:27 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while ((n != 0))
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*maloooc(int *len, int n)
{
	*len = numlen(n);
	return (ft_calloc((*len + 1), sizeof(char)));
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*final;
	int		i;

	sign = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	final = maloooc(&i, n);
	if (!final)
		return (NULL);
	final[0] = '0';
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	while (i)
	{
		final[i - 1] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	if (sign == -1)
		final[i] = '-';
	return (final);
}

// int main()
// {
// 	int                n = -21456;
//         char        *str;

//         str = ft_itoa(n);
//         printf("%s\n", str);
//         free(str);
//         return (0);
// }