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

# include "../minishell.h"

void	tokenization(char *input, t_shell *shell)
{
	t_token	*token;
	int		start;
	int		end;
	int		x;
	token = malloc(sizeof(t_token));
	if (!token)
		shell_error_message(strerror(errno));
	x= 0;
	start = 0;
	end = 0;
	while (input[x])
	{
		start = x;
		while (!ft_strchr("<>|", input[x]) && input[x])
			x++;
		end = x;
		token->value = ft_substr(input, start, end - start);
		if (!token)
			shell_error_message(strerror(errno));
		printf("debug: %s\n", token->value);
		token = token->next;
		x = handle_spscial_char(input, x, shell);
	}
	while (token->value)
	{
		ft_printf("token: ");
		ft_putstr_fd(token->value, 1);
		ft_putchar_fd('\n', 1);
		token = token->next;
	}
}

int	handle_spscial_char(char *input, int x, t_shell *shell)
{
	if (input[x] == '<')
	{
		x++;
		if (input[x] == '<')
			shell->token->value = ft_strdup("<");
		else
		{
			x++;
			shell->token->value = ft_strdup("<<");
		}
	}
	else if (input[x] == '>')
	{
		x++;
		if (input[x] == '>')
			shell->token->value = ft_strdup(">");
		else
		{
			x++;
			shell->token->value = ft_strdup(">>");
		}
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
	printf("%s\n", "print_token");
	while (shell->token->value)
	{
		ft_printf("token: ");
		ft_putstr_fd(shell->token->value, 1);
		ft_putchar_fd('\n', 1);
		shell->token = shell->token->next;
	}
	
}