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


int	ft_export(char *input, t_shell *shell)
{
	char	*key;
	char	*value;
	char	*tmp;

	key = ft_strtrim(input + 6, " ");
	if (!key || ft_strlen(key) == 0)
	{
		free(key);
		return (1);
	}
	value = ft_strchr(key, '=');
	if (value)
	{
		*value = '\0';
		value++;
	}
	tmp = get_env_value(key, shell->env);
	if (tmp)
	{
		free(tmp);
		set_env_value(key, value, shell->env);
	}
	else
		add_env(key, value, shell->env);
	free(key);
	return (1);
}

void	add_env(char *key, char *value, t_env *env)
{
	t_env	*new;
	t_env	*tmp;

	new = malloc(sizeof(t_env));
	if (!new)
		shell_error_message(strerror(errno));
	new->value = ft_strjoin(key, "=");
	if (!new->value)
		shell_error_message(strerror(errno));
	if (value)
	{
		new->value = ft_strjoin(new->value, value);
		if (!new->value)
			shell_error_message(strerror(errno));
	}
	new->next = NULL;
	tmp = env;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
