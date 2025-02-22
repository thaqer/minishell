/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:16:15 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/03 17:01:50 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	str = (char *)malloc(nmemb * size);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_memset(str, 0, nmemb * size);
	return ((void *)str);
}
