/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:09:59 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/22 15:22:27 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_exit(char *input, t_shell *shell)
{
	(void)input;
	cleanup(shell);
	ft_putstr_fd("exit!\n", 1);
	return (1);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->value);
		free(tmp);
		tmp = NULL;
	}
}

void	cleanup(t_shell *shell)
{
	if (shell->token)
	{
		free_token(shell);
		shell->token = NULL;
	}
	if (shell->env)
	{
		free_env(shell->env);
		shell->env = NULL;
	}
	ft_free_array(shell->paths);
	ft_free_array(shell->args);
}
