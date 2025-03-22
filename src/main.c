/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:12:12 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/22 15:22:11 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int ac, char **av, char **env)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	shell.env = get_env(env);
	setup_signals();
	while (1)
	{
		handle_prompt(&shell);
		if (!shell.input)
		{
			ft_exit(shell.input, &shell);
			break ;
		}
		tokenization(shell.input, &shell);
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
