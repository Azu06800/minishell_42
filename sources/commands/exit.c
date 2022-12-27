/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:10:04 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/27 19:25:53 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(t_parser_token *token, t_minishell *minishell)
{
	//int	i;

	(void) minishell;
	(void) token;
	//i = -1;
	//while (token[++i])
	//	free(token[i]);
	//free(token[i]);
	//free(token);
	exit(0);
}
