/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:47:48 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/10 12:40:32 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_parser_token *token)
{
	int	i;

	(void) token;
	i = 0;
	while (i < g_minishell->env_size)
	{
		printf("%s=%s", g_minishell->env[i].name, g_minishell->env[i].value);
		printf("\n");
		i++;
	}
	return (0);
}
