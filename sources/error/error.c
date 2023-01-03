/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:07:48 by baroun            #+#    #+#             */
/*   Updated: 2023/01/03 16:43:49 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	err_not_found(char *cmd)
{
	write(2, "minishell: command not found: ", 30);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}

void	err_perm_denied(char *cmd)
{
	write(2, "minishell: permission denied: ", 30);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}

void	err_no_file_or_dir(char *cmd)
{
	write(2, "minishell: no such file or directory: ", 38);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
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
		write(2, "minishell: syntax error unclosed quote\n", 39);
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
