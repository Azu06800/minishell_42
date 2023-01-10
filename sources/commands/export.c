/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:46:42 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/10 14:43:07 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	print_export()
{
	int	i;

	i = 0;
	while (i < g_minishell->env_size)
	{
		printf("export %s=\"%s\"", g_minishell->env[i].name,
			g_minishell->env[i].value);
		printf("\n");
		i++;
	}
	return (0);
}

int	ft_export(t_parser_token *token)
{
	int		i;
	char	**tmp;

	i = 0;
	if (token->command[1] == NULL)
		return (print_export());
	while (token->command[++i])
	{
		if (!ft_strchr(token->command[i], '='))
			return (0);
		tmp = ft_split(token->command[i], '=');
		if (ft_getenv(tmp[0]) != NULL)
			ft_modenv(tmp[0], tmp[1]);
		if (ft_isalpha(tmp[0][0]) == 0)
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(tmp[0], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		else
			ft_addenv(tmp[0], tmp[1]);
		ft_split_free(tmp);
	}
	return (0);
}
