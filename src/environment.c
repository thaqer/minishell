#include "../minishell.h"

t_env	*get_env(char **env)
{
	t_env	*env_list;
	t_env	*tmp;
	int		i;

	i = 0;
	env_list = NULL;
	while (env[i])
	{
		tmp = malloc(sizeof(t_env));
		if (!tmp)
			return (NULL);
		tmp->value = ft_strdup(env[i]);
		if (!tmp->value)
			return (NULL);
		tmp->next = 0;
		if (!env_list)
			env_list = tmp;
		else
		{
			tmp->next = env_list;
			env_list = tmp;
		}
		i++;
	}
	return (env_list);
}

void	print_env(t_env *env)
{
	while (env)
	{
		ft_putstr_fd(env->value, 1);
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
}
