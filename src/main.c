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

int	main(int ac, char **av, char **env)
{
	t_shell	shell;
	char	*input;

	(void)ac;
	(void)av;
	shell.env = NULL;
	if (env)
		shell.env = get_env(env);
	setup_signals();
	while (1)
	{
		input = readline(PROMPT);
		if (!input)
		{
			ft_putstr_fd("exit\n", 1);
			break ;
		}
		if (*input)
			add_history(input);
		if (ft_strncmp(input, "exit", 4) == 0)
		{
			free(input);
			break ;
		}
		if (ft_strncmp(input, "env", 3) == 0)
			print_env(shell.env);
		else
			execute_command(input, &shell);
		free(input);
	}
	rl_clear_history();
	return (0);
}
