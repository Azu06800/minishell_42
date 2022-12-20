/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:46:42 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/17 15:03:48 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: Export env
int	ft_export(char **token, t_minishell *minishell)
{
	int	i;

	(void) token;
	i = -1;
	while (minishell->env[++i])
		printf("%s\n", minishell->env[i]);
	return (0);
}
