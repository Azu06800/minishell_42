/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:25:02 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/10 20:15:42 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_builtin(t_parser_token *token)
{
	if (token->command[0] && !ft_strcmp(token->command[0], "echo"))
		return (ft_echo(token));
	else if (token->command[0] && !ft_strcmp(token->command[0], "cd"))
		return (ft_cd(token));
	else if (token->command[0] && !ft_strcmp(token->command[0], "pwd"))
		return (ft_pwd(token));
	else if (token->command[0] && !ft_strcmp(token->command[0], "export"))
		return (ft_export(token));
	else if (token->command[0] && !ft_strcmp(token->command[0], "unset"))
		return (ft_unset(token));
	else if (token->command[0] && !ft_strcmp(token->command[0], "env"))
		return (ft_env(token));
	else if (token->command[0] && !ft_strcmp(token->command[0], "exit"))
		return (ft_exit(token));
	else if (token->command[0] && !ft_strcmp(token->command[0], "clear"))
		return (ft_clear(token));
	else if (token->command[0] && !ft_strcmp(token->command[0], "history"))
		return (ft_history(token));
	return (0);
}

int	is_builtin(char *str)
{
	int	i;

	i = 0;
	while (g_minishell->builtins[i])
	{
		if (!ft_strcmp(str, g_minishell->builtins[i]))
			return (1);
		i++;
	}
	return (0);
}

int	execute_builtin(t_parser_token *token, int fd_in, int fd_out)
{
	int	status;

	redir_fds(fd_in, fd_out);
	status = exec_builtin(token);
	ft_modenv("$?", ft_itoa(status));
	return (status);
}
