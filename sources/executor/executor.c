/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:31:26 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/02 16:37:47 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

pid_t	g_pid;

void	exec_bin(t_parser_token *token)
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
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
		}
	}
}

void	ft_executor(t_parser_token *tokens, t_minishell *minishell)
{
	size_t	i;

	i = 0;
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens->type == TOKEN_CMD)
		{
			if (tokens->command[0] && !ft_strcmp(tokens->command[0], "echo"))
				ft_echo(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "cd"))
				ft_cd(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "pwd"))
				ft_pwd(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "export"))
				ft_export(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "unset"))
				ft_unset(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "env"))
				ft_env(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "exit"))
				ft_exit(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "clear"))
				ft_clear(tokens, minishell);
			else
				exec_bin(tokens);
		}
		i++;
	}
}
