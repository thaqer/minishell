/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:12:12 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/08 00:18:27 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int ac, char **av, char **env)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	shell.env = NULL;
	if (env)
		shell.env = get_env(env);
	char *str;
	setup_signals();
	shell.token = calloc(1, sizeof(t_token));
	if (!shell.token)
		shell_error_message(strerror(errno));
	while (1)
	{
		shell.pwd = getcwd(NULL, 0);
		str = ft_strjoin(PROMPT, shell.pwd);
		str = ft_strjoin(str, "$ ");
		shell.input = readline(str);
		if (!shell.input)
		{
			ft_putstr_fd("exit\n", 1);
			break ;
		}
		tokenization(shell.input, &shell);
		// if (ft_strlen(shell.input) > 0)
		// 	add_history(shell.input);
		// if (!it_is_builtin(&shell))
		// 	execute_command(shell.input, &shell);
		free(shell.input);
	}
	free_env(shell.env);
	rl_clear_history();
	return (0);
}
