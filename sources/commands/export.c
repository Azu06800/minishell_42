/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:46:42 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/27 19:25:08 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: Export env
int	ft_export(t_parser_token *token, t_minishell *minishell)
{
	int	i;

	(void) token;
	i = -1;
	while (minishell->env[++i])
		printf("%s\n", minishell->env[i]);
	return (0);
}
