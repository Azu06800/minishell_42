/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:47:48 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 16:23:51 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_parser_token *token, t_minishell *minishell)
{
	int	i;

	(void) token;
	i = 0;
	while (i < minishell->env_size)
	{
		printf("%s=%s", minishell->env[i].name, minishell->env[i].value);
		printf("\n");
		i++;
	}
	exit(0);
	return (0);
}
