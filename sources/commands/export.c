/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:46:42 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/01 23:26:27 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: Export env
int	ft_export(t_parser_token *token, t_minishell *minishell)
{
	int		i;
	char	**tmp;

	i = 1;
	(void)tmp;
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
		// export a=b c=d
	}
	return (0);
}
