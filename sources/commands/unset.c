/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:40:18 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/02 17:12:47 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(t_parser_token *token, t_minishell *minishell)
{
	if (token->command[1] != NULL)
	{
		if (ft_getenv(minishell, token->command[1]) != NULL)
			ft_delenv(minishell, token->command[1]);
	}
	return (0);
}
