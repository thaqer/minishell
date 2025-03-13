/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:53:42 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/08 00:09:24 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(char *input, t_shell *shell)
{
	int	i;
	int	n_flag;

	i = 4;
	n_flag = 0;
	if (ft_strncmp(input + i, "-n", 2) == 0)
	{
		n_flag = 1;
		while (input[i] == 'n')
			i++;
	}
	while (input[i] == ' ')
		i++;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '\"')
			i = handle_quotations(shell, input, i);
		else if (input[i] == '$')
			i = expand_env(shell, input, i);
		else
			write(1, &input[i++], 1);
	}
	if (!n_flag)
		write(1, "\n", 1);
	return (1);
}

int	handle_quotations(t_shell *shell, char *input, int i)
{
		if (input[i] == '\"')
			i = double_quote(shell, input, i);
		else if (input[i] == '\'')
			i = single_quote(shell, input, i);
		return (i);
}
	
int	single_quote(t_shell *shell, char *input, int i)
{
	(void)shell;
	i++;
	while (input[i] && input[i] != '\'')
	{
		write(1, &input[i], 1);
		i++;
	}
	return (i);
}

int	double_quote(t_shell *shell, char *input, int i)
{
	i++;
	while (input[i] && input[i] != '\"')
	{
		if (input[i] != '$')
			write(1, &input[i], 1);
		else if (input[i] == '$')
			i = expand_env(shell, input, i);
		i++;
	}
	return (i);
}
