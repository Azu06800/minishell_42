/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:46:42 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 22:21:36 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_export(t_minishell *minishell)
{
	int	i;

	i = 0;
	while (i < minishell->env_size)
	{
		printf("declare -x %s=\"%s\"", minishell->env[i].name,
			minishell->env[i].value);
		printf("\n");
		i++;
	}
}

int	ft_export(t_parser_token *token, t_minishell *minishell)
{
	int		i;
	char	**tmp;

	i = 0;
	if (token->command[1] == NULL)
	{
		print_export(minishell);
		return (0);
	}
	while (token->command[++i])
	{
		tmp = ft_split(token->command[i], '=');
		if (ft_getenv(minishell, tmp[0]) != NULL)
			ft_modenv(minishell, tmp[0], tmp[1]);
		if (ft_isalpha(tmp[0][0]) == 0)
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(tmp[0], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		else
			ft_addenv(minishell, tmp[0], tmp[1]);
	}
	return (0);
}
