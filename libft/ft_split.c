/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:47:58 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/04 12:24:27 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freeee(char **str, int i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (NULL);
}

static int	stringlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	*small_malloc(char const *s, char c)
{
	char	*word;
	int		len;
	int		j;

	len = stringlen(s, c);
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static int	cnum(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count;
	int		i;

	count = cnum(s, c);
	str = (char **)malloc((count + 1) * sizeof(char *));
	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		str[i] = small_malloc(s, c);
		if (str[i] == NULL)
			return (freeee(str, i));
		s += stringlen(s, c);
		i++;
	}
	str[count] = NULL;
	return (str);
}
