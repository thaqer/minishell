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
	char	*tmp;

	key = ft_strtrim(input + 6, " ");
	veiled_key(key, shell);
	//hnadle "export with no argument"
	handle_equal_sign(key, &value);
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

//handle "if key is (char or digit(use ft_islnum) or _) and begin with (char or _)"  Done ;)
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
		}
		if (key[i] != '=')
		{
			shell->exit_status = 1;
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(key, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
		}
	}	
}

void	handle_equal_sign(char *key, char *value)
{
	int	i;

	i = 0;
	if (ft_strchr(key, '='))
	{
		*value = key[i];
		key[i] = '\0';
	}
	else
		*value = '\0';
}