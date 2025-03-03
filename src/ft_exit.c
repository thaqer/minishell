/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:09:59 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/03/01 23:10:12 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_exit(char *input, t_shell *shell)
//here we need to call a functions to clean up the memory and free the linked list
{
	(void)input;
	(void)shell;
	exit(0);
}
