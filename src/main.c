/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:12:12 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/08 03:35:43 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	}
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	shell.env = NULL;
	if (env)
		shell.env = get_env(env);
	setup_signals();
	while (1)
	{
		shell.input = readline(PROMPT);
		if (!shell.input)
		{
			ft_putstr_fd("exit\n", 1);
			break ;
		}
		if (ft_strlen(shell.input) > 0)
			add_history(shell.input);
		if (!it_is_builtin(&shell))
			execute_command(shell.input, &shell);
		free(shell.input);
	}
	free_env(shell.env);
	rl_clear_history();
	return (0);
}
