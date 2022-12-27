/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:12:46 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/27 19:24:14 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(t_parser_token *token, t_minishell *minishell)
{
	int	i;
	int	nflag;

	(void) minishell;
	i = 1;
	nflag = 0;
	if (token->command[1] && ft_strcmp(token->command[1], "-n") == 0)
	{
		nflag = 1;
		i++;
	}
	while (token->command[i])
	{
		printf("%s", token->command[i]);
		if (token->command[i + 1])
			printf(" ");
		i++;
	}
	if (!nflag)
		printf("\n");
	return (0);
}
