/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:47:48 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/17 15:03:37 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(char **token, t_minishell *minishell)
{
	int	i;

	(void) token;
	i = -1;
	while (minishell->env[++i])
		printf("%s\n", minishell->env[i]);
	return (0);
}
