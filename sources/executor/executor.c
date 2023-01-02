/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:31:26 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/02 17:16:38 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

pid_t	g_pid;

int	exec_bin(t_parser_token *token)
{
	pid_t	pid;
	int		status;

	pid = fork();
	g_pid = pid;
	if (pid == 0)
	{
		if (execvp(token->command[0], token->command) == -1)
		{
			perror("execvp");
			return (1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (1);
		}
	}
	return (0);
}

int	exec_builtin(t_parser_token *token, t_minishell *minishell)
{
	if (token->command[0] && !ft_strcmp(token->command[0], "echo"))
		return (ft_echo(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "cd"))
		return (ft_cd(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "pwd"))
		return (ft_pwd(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "export"))
		return (ft_export(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "unset"))
		return (ft_unset(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "env"))
		return (ft_env(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "exit"))
		return (ft_exit(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "clear"))
		return (ft_clear(token, minishell));
	return (2);
}

int	ft_executor(t_parser_token *tokens, t_minishell *minishell)
{
	size_t	i;

	i = 0;
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens->type == TOKEN_CMD)
		{
			if (exec_builtin(tokens, minishell) == 0)
				return (0);
			else if (exec_builtin(tokens, minishell) == 1)
				return (1);
			else if (exec_builtin(tokens, minishell) == 2)
			{
				if (exec_bin(tokens) == 0)
					return (0);
				if (exec_bin(tokens) == 1)
					return (1);
			}
		}
		i++;
	}
	return (0);
}
