/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:31:26 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/03 17:42:04 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

pid_t	g_pid;

int	exec_1_bin(t_parser_token *token)
{
	pid_t	pid;
	int		status;
	int		pipefd[2];
	char	buffer[BUFFER_SIZE];
	size_t	output_size;
	size_t	bytes_read;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid = fork();
	g_pid = pid;
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
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
		close(pipefd[1]);
		output_size = 0;
		while ((bytes_read = read(pipefd[0], buffer, BUFFER_SIZE)) > 0)
		{
			output_size += bytes_read;
			token->output = realloc(token->output, output_size);
			memcpy(token->output + output_size - bytes_read, buffer, bytes_read);
			if (bytes_read < BUFFER_SIZE)
			{
				break ;
			}
		}
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (1);
		}
		token->output_size = output_size;
		fwrite(token->output, token->output_size, 1, stdout);
		close(pipefd[0]);
	}
	return (0);
}

int	exec_bin(t_parser_token *token)
{
	(void) token;
	return (0);
	//int	i;
//
	//i = 0;
	//while (token->command[i])
	//{
	//	if (token->type == TOKEN_REDIR && token->redirection[0] == REDIR_PIPE)
	//	{
	//		
	//	}
	//}
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
