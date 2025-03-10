/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-10 18:15:53 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-03-10 18:15:53 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	tokenization(char *input, t_shell *shell)
{
	char	*start;
	char	*end;
	char	*temp;

	while (*input)
	{
		start = input;
		while (*input && *input != '\'' && *input != '\"' && *input != '|' 
				&& *input != ';' && *input != '(' && *input != ')' 
				&& *input != '<' && *input != '>')
			input++;
		end = input;
	}
}