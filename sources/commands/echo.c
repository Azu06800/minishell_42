/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:12:46 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/06 17:33:35 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void echo_quote(char *str)
{
	int i;

	i = -1;
	if (ft_isquote(str[0]))
		i++;
	while (str[++i])
		write(1, &str[i], 1);
}

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
