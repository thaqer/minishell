/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:06:47 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/28 14:44:43 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


//handle "export key with no value (there is no =)"
//handle "export key with no value (there is = but no value)"
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
		return (1);
	}
	if (get_env_value(key, shell->env))
		set_env_value(key, value, shell->env);
	else
		add_env(key, value, shell->env);
	free(key);
	return (1);
}

void	add_env(char *key, char *value, t_env *env)
{
	t_env	*new;
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(tmp->value, key, ft_strlen(key)) == 0 && tmp->value[ft_strlen(key)] == '=')
		{
			free(tmp->value);
			tmp->value = ft_strjoin(key, "=");
			if (value)
			{
				char *tmp_value = ft_strjoin(tmp->value, value);
				free(tmp->value);
				tmp->value = tmp_value;
			}
			return;
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
		char *tmp_value = ft_strjoin(new->value, value);
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
		if (key[i] == '=')
			shell->exit_status = 0;
		else
			shell->exit_status = 1;
	}
	else
	{
		shell->exit_status = 1;
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(key, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
}
