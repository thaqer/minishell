/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:12:31 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/06 01:20:01 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset(char *input, t_shell *shell)
{
	char	*key;
	t_env	*tmp;
	t_env	*prev;

	// Extract the key from the input by trimming the leading and trailing spaces
	key = ft_strtrim(input + 5, " ");
	// Initialize tmp to point to the head of the environment list
	tmp = shell->env;
	prev = NULL;
	// Iterate through the environment list
	while (tmp)
	{
		// Compare the current environment variable with the key
		if (ft_strncmp(tmp->value, key, ft_strlen(key)) == 0)
		{
			// If a match is found, unlink the node from the list
			if (prev)
				prev->next = tmp->next;
			else
				shell->env = tmp->next;
			// Free the memory allocated for the environment variable
			free(tmp->value);
			free(tmp);
			free(key);
			return (1);
		}
		// Move to the next node in the list
		prev = tmp;
		tmp = tmp->next;
	}
	// Free the memory allocated for the key
	free(key);
	return (1);
}
