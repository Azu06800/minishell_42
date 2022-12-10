/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:07:48 by baroun            #+#    #+#             */
/*   Updated: 2022/12/10 11:29:36 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	err_not_found(char *cmd)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
}

void	err_perm_denied(char *cmd)
{
	ft_putstr_fd("minishell: permission denied: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
}

int	err_unclosed_quote(char *str)
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

int	check_cmd(char *str, t_minishell *minishell)
{
	char	**cmd;

	cmd = minishell->builtins;
	if (ft_cmdcmp(str, cmd) == 1)
	{
		printf("minishell: command not found: %s\n", str);
		return (1);
	}
	return (0);
}
