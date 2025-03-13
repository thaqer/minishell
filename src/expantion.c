/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:41:42 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/08 00:09:24 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
int	expand_env(t_shell *shell, char *key, int i)
{
	char	*value;
	char	*temp;
	int	j;

	j = i + 1;
	while (key[j] && (ft_isalnum(key[j]) || key[j] == '_'))
		j++;
	temp = ft_substr(key, i + 1, j - (i + 1));
	if (temp)
	{
		value = get_env_value(temp, shell->env);
		if (value)
		{
			ft_putstr_fd(value, 1);
		}
		free(temp);
	}
	return (j - 1);
}
