/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:46:42 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 16:53:06 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: Export env
//new
/*int	ft_export(t_parser_token *token, t_minishell *minishell)
{
	int		i;
	char	**tmp;

	if (token->command[1] == NULL)
	{
		i = -1;
		while (++i < minishell->env_size)
			printf("declare -x %s=\"%s\"\n", minishell->env[i].name,
				minishell->env[i].value);
	}
	else
	{
		i = 0;
		while (token->command[++i] != NULL)
		{
			tmp = ft_split(token->command[i], '=');
			if (tmp[1] != NULL)
				ft_modenv(minishell, tmp[0], tmp[1]);
			i++;
		}
	}
	exit(0);
	return (0);
}*/

//old
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
	exit(0);
	return (0);
}
