/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:12:46 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/20 18:46:57 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(char **token, t_minishell *minishell)
{
	int	i;
	int	nflag;

	(void) minishell;
	i = 1;
	nflag = 0;
	if (token[1] && ft_strcmp(token[1], "-n") == 0)
	{
		nflag = 1;
		i++;
	}
	while (token[i])
	{
		printf("%s", token[i]);
		if (token[i + 1])
			printf(" ");
		i++;
	}
	if (!nflag)
		printf("\n");
	return (0);
}
