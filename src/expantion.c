/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:41:42 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/06 01:43:30 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	expand_env(t_shell *shell)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (shell->args[i])
	{
		if (shell->args[i][0] == '$')
		{
			tmp = ft_strdup(shell->args[i] + 1);
			tmp2 = get_env_value(tmp, shell->env);
			free(tmp);
			free(shell->args[i]);
			shell->args[i] = tmp2;
		}
		i++;
	}
}
