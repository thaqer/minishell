/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:15:53 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/04/06 00:37:08 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	tokenization(char *input, t_shell *shell)
{
	int		i = 0;
	int		start;
	t_token	*new_token;
	t_token	*last;

	shell->token = NULL;
	while (input[i])
	{
		while (input[i] == ' ' && input[i])
			i++;

		if (input[i] && ft_strchr("<>|", input[i]))
		{
			i = handle_spscial_char(input, i, shell);
			continue;
		}

		start = i;
		while (input[i] && !ft_strchr("<>| ", input[i]))
			i++;

		if (i > start)
		{
			new_token = malloc(sizeof(t_token));
			if (!new_token)
				shell_error_message("malloc error");
			new_token->value = ft_substr(input, start, i - start);
			if (!new_token->value)
			{
				free(new_token);
				shell_error_message("malloc error");
			}
			new_token->next = NULL;

			if (!shell->token)
				shell->token = new_token;
			else
			{
				last = shell->token;
				while (last->next)
					last = last->next;
				last->next = new_token;
			}
		}
	}
}

int	handle_spscial_char(char *input, int i, t_shell *shell)
{
	t_token *new_token;
	t_token *last;
	int start = i;
	int len = 1;

	if ((input[i] == '<' && input[i + 1] == '<') || (input[i] == '>' && input[i + 1] == '>'))
		len = 2;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		shell_error_message("malloc error");
	new_token->value = ft_substr(input, start, len);
	if (!new_token->value)
	{
		free(new_token);
		shell_error_message("malloc error");
	}
	new_token->next = NULL;

	if (!shell->token)
		shell->token = new_token;
	else
	{
		last = shell->token;
		while (last->next)
			last = last->next;
		last->next = new_token;
	}
	return (i + len);
}

int	handle_pipe(char *input, int x, t_shell *shell)
{
	x++;
	if (input[x] == '|')
		shell_error_message("syntax error near unexpected token `||'");
	else
		shell->token->value = ft_strdup("|");
	shell->pip_num++;
	return (x);
}

void	print_token(t_shell *shell)
{
	t_token	*token = shell->token;

	while (token)
	{
		if (token->value && *token->value)
			printf("token: %s\n", token->value);
		token = token->next;
	}
}

void	free_token(t_shell *shell)
{
	t_token	*tmp;

	while (shell->token)
	{
		tmp = shell->token;
		shell->token = shell->token->next;
		if (tmp->value)
		{
			free(tmp->value);
			tmp->value = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
}
