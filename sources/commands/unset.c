/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:40:18 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/17 15:03:58 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: If variable has been set, then delete it.
int	ft_unset(char **token, t_minishell *minishell)
{
	int	i;
	int	j;

	(void) minishell;
	i = 0;
	while (token[++i])
	{
		j = -1;
		while (minishell->env[++j])
		{
			if (ft_strncmp(minishell->env[j], token[i], ft_strlen(token[i])) == 0)
			{
				free(minishell->env[j]);
				minishell->env[j] = NULL;
			}
		}
	}
	return (0);
}
