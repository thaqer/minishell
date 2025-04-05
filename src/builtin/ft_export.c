/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:06:47 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/04/06 00:39:04 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_export(char *input, t_shell *shell)
{
	char	*key;
	char	*value;
	char	**temp;
	char	*equal_sign;

	key = ft_strtrim(input + 6, " ");
	temp = ft_split(key, ' ');
	if (!temp)
		shell_error_message(strerror(errno));
	while (*temp)
	{
		equal_sign = ft_strchr(*temp, '=');
		if (equal_sign)
		{
			value = ft_strdup(equal_sign + 1);
			*equal_sign = '\0';
		}
		else if (!equal_sign)
		{
			temp++;
			continue ;
		}
		veiled_key(*temp, shell);
		if (shell->exit_status == 1)
		{
			free(key);
			free(value);
			free(temp);
			return (1);
		}
		handle_value(value);
		if (get_env_value(*temp, shell->env))
			set_env_value(*temp, value, shell->env);
		else
			add_env(*temp, value, shell->env);
		free(value);
		temp++;
	}
	return (1);
}

void	handle_value(char *value)
{
	if (value)
	{
		if (value[0] == '\"' && value[ft_strlen(value) - 1] == '\"')
		{
			value[ft_strlen(value) - 1] = '\0';
			value++;
		}
		if (value[0] == '\'' && value[ft_strlen(value) - 1] == '\'')
		{
			value[ft_strlen(value) - 1] = '\0';
			value++;
		}
	}
}

void	add_env(char *key, char *value, t_env *env)
{
	t_env	*new;
	t_env	*tmp;
	char	*tmp_value;

	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(tmp->value, key, ft_strlen(key)) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strjoin(key, "=");
			if (value)
			{
				tmp_value = ft_strjoin(tmp->value, value);
				free(tmp->value);
				tmp->value = tmp_value;
			}
			return ;
		}
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_env));
	if (!new)
		shell_error_message(strerror(errno));
	new->value = ft_strjoin(key, "=");
	if (!new->value)
		shell_error_message(strerror(errno));
	if (value)
	{
		tmp_value = ft_strjoin(new->value, value);
		free(new->value);
		new->value = tmp_value;
		if (!new->value)
			shell_error_message(strerror(errno));
	}
	new->next = NULL;
	tmp = env;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	veiled_key(char *key, t_shell *shell)
{
	int	i;

	i = 0;
	while (key[i] == ' ')
		i++;
	if (key[0] == '_' || ft_isalpha(key[0]))
	{
		while (key[i] && key[i] != ' ' && key[i] != '=')
		{
			if (!ft_isalnum(key[i]) && key[i] != '_')
			{
				shell->exit_status = 1;
				ft_putstr_fd("minishell: export: `", 2);
				ft_putstr_fd(key, 2);
				ft_putstr_fd("': not a valid identifier\n", 2);
				return ;
			}
			i++;
		}
	}
	else
	{
		shell->exit_status = 1;
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(key, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
}
