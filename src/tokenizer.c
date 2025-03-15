/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:15:53 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/15 18:17:19 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void	tokenization(char *input, t_shell *shell)
{
	t_token	*token;
	t_token	*head;
	int		start;
	int		end;
	int		x;

	token = malloc(sizeof(t_token));
	if (!token)
		shell_error_message(strerror(errno));
	head = token;
	x = 0;
	while (input[x])
	{
		start = x;
		while (!ft_strchr("<>|", input[x]) && input[x])
			x++;
		end = x;
		token->value = ft_substr(input, start, end - start);
		if (!token->value)
			shell_error_message(strerror(errno));
		x = handle_spscial_char(input, x, shell);
		if (input[x])
		{
			token->next = malloc(sizeof(t_token));
			if (!token->next)
				shell_error_message(strerror(errno));
			token = token->next;
		}
	}
	token->next = NULL;
	shell->token = head;
	print_token(shell);
}

int	handle_spscial_char(char *input, int x, t_shell *shell)
{
	if (input[x] == '<')
	{
		x++;
		if (input[x] == '<')
			shell->token->value = ft_strdup("<<");
		else
			shell->token->value = ft_strdup("<");
	}
	else if (input[x] == '>')
	{
		x++;
		if (input[x] == '>')
			shell->token->value = ft_strdup(">>");
		else
			shell->token->value = ft_strdup(">");
	}
	else if (input[x] == '|')
		x = handle_pipe(input, x, shell);
	return (x);
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
	t_token *token = shell->token;
	while (token)
	{
		ft_printf("token: ");
		ft_putstr_fd(token->value, 1);
		ft_putchar_fd('\n', 1);
		token = token->next;
	}
}