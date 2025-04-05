/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:12:12 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/04/06 00:30:28 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int ac, char **av, char **env)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	setup_shell(&shell, env);
	while (1)
	{
		handle_prompt(&shell);
		if (!shell.input)
		{
			ft_exit(shell.input, &shell);
			break ;
		}
		tokenization(shell.input, &shell);
		print_token(&shell);
		free_token(&shell);
		free(shell.input);
		shell.input = NULL;
	}
	free_env(shell.env);
	rl_clear_history();
	return (0);
}

void	handle_prompt(t_shell *shell)
{
	char	*str;
	char	*temp;

	shell->pwd = getcwd(NULL, 0);
	temp = ft_strjoin(PROMPT, shell->pwd);
	str = ft_strjoin(temp, "$ ");
	free(shell->pwd);
	shell->input = readline(str);
	free(str);
	free(temp);
}

void	setup_shell(t_shell *shell, char **env)
{
	shell->env = get_env(env);
	shell->token = NULL;
	shell->pwd = NULL;
	shell->input = NULL;
	shell->args = NULL;
	shell->paths = NULL;
	shell->env_array = NULL;
	shell->path = NULL;
	shell->command = NULL;
	shell->full_path = NULL;
	shell->exit_status = 0;
	setup_signals();
}