/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:12:31 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/04/06 00:39:10 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_unset(char *input, t_shell *shell)
{
	char	*key;
	t_env	*tmp;
	t_env	*prev;

	key = ft_strtrim(input + 5, " ");
	tmp = shell->env;
	prev = NULL;
	while (tmp)
	{
		if (ft_strncmp(tmp->value, key, ft_strlen(key)) == 0)
		{
			if (prev)
				prev->next = tmp->next;
			else
				shell->env = tmp->next;
			free(tmp->value);
			free(tmp);
			free(key);
			return (1);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	free(key);
	return (1);
}
