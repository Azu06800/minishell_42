/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:46:42 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/02 17:18:37 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: Export env
int	ft_export(t_parser_token *token, t_minishell *minishell)
{
	int		i;
	char	**tmp;

	i = 1;
	if (token->command[1] == NULL)
	{
		i = 0;
		while (i < minishell->env_size)
		{
			printf("declare -x %s=\"%s\"", minishell->env[i].name,
				minishell->env[i].value);
			printf("\n");
			i++;
		}
	}
	else
	{
		while (token->command[i] != NULL)
		{
			tmp = ft_split(token->command[i], '=');
			if (tmp[1] != NULL)
				ft_modenv(minishell, tmp[0], tmp[1]);
			i++;
		}
	}
	return (0);
}
