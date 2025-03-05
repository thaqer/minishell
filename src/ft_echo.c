/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:53:42 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/02 21:54:29 by tbaniatt         ###   ########.fr       */
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
		if (input[i] == '$')
			i = ft_dollar(input, i, shell);
		else
			write(1, &input[i], 1);
		i++;
	}
	if (!n_flag)
		write(1, "\n", 1);
	return (1);
}

int	ft_dollar(char *input, int i, t_shell *shell)
