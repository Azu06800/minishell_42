/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:40:18 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/27 19:25:41 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: If variable has been set, then delete it.
int	ft_unset(t_parser_token *token, t_minishell *minishell)
{
	int	i;
	int	j;

	(void) minishell;
	i = 0;
	while (token->command[++i])
	{
		j = -1;
		while (minishell->env[++j])
		{
			if (ft_strncmp(minishell->env[j], token->command[i],
					ft_strlen(token->command[i])) == 0)
			{
				free(minishell->env[j]);
				minishell->env[j] = NULL;
			}
		}
	}
	return (0);
}
