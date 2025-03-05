/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:06:47 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/06 01:38:14 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// handle "export key with no value (there is no =)"
// handle "export key with no value (there is = but no value)"
int	ft_export(char *input, t_shell *shell)
{
	char	*key;
	char	*value;
	char	*equal_sign;

	key = ft_strtrim(input + 6, " ");
	equal_sign = ft_strchr(key, '=');
	if (equal_sign)
	{
		value = ft_strdup(equal_sign + 1);
		*equal_sign = '\0';
	}
	else
		value = NULL;
	veiled_key(key, shell);
	if (shell->exit_status == 1)
	{
		free(key);
		free(value);
		return (1);
	}
	handle_value(char *value);
	if (get_env_value(key, shell->env))
		set_env_value(key, value, shell->env);
	else
		add_env(key, value, shell->env);
	free(key);
	free(value);
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
