/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:07:48 by baroun            #+#    #+#             */
/*   Updated: 2022/12/06 18:18:24 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	error_quote(char *str)
{
	int	i;
	int	quote;
	int	dquote;


	i = -1;
	quote = 0;
	dquote = 0;
	while (str[++i])
	{
		if (str[i] == '\'' && dquote % 2 == 0)
			quote++;
		if (str[i] == '\"' && quote % 2 == 0)
			dquote++;
	}
	if (quote % 2 == 1 || dquote % 2 == 1)
	{
		printf("minishell: syntax error unclosed quote\n");
		return (1);
	}
	return (0);
}

int	check_cmd(char *str)
{
	char **cmd;

	cmd = listofcmd();
	if (ft_cmdcmp(str, cmd) == 1)
	{
		printf("minishell: command not found: %s\n", str);
		return (1);
	}
	return (0);
}

char **listofcmd(void)
{
	char **cmd;

	cmd = (char **)malloc(sizeof(char *) * 7);
	cmd[0] = "echo";
	cmd[1] = "cd";
	cmd[2] = "pwd";
	cmd[3] = "export";
	cmd[4] = "unset";
	cmd[5] = "env";
	cmd[6] = "exit";
	return (cmd);
}
