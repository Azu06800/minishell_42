/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:31:26 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/01 23:45:08 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_bin(t_parser_token *tokens)
{
	int		fd_in;
	int		fd_out;
	int		pipe_fds[2];
	pid_t	pid;
	int		i;

	fd_in = STDIN_FILENO;
	fd_out = STDOUT_FILENO;
	i = 0;
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens[i].type == TOKEN_REDIR && tokens[i].redirection[0] == REDIR_IN)
			fd_in = open(tokens[i + 1].input, O_RDONLY);
		else if (tokens[i].type == TOKEN_REDIR && tokens[i].redirection[0] == REDIR_OUT)
			fd_out = open(tokens[i + 1].output, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		else if (tokens[i].type == TOKEN_REDIR && tokens[i].redirection[0] == REDIR_APPEND)
			fd_out = open(tokens[i + 1].output, O_CREAT | O_WRONLY | O_APPEND, 0666);
		else if (tokens[i].type == TOKEN_REDIR && tokens[i].redirection[0] == REDIR_PIPE)
		{
			if (pipe(pipe_fds) < 0)
			{
				perror("pipe");
				exit(EXIT_FAILURE);
			}
			fd_out = pipe_fds[1];
			fd_in = pipe_fds[0];
		}
		else if (tokens[i].type == TOKEN_CMD)
		{
			pid = fork();
			if (pid == 0)
			{
				dup2(fd_in, STDIN_FILENO);
				dup2(fd_out, STDOUT_FILENO);
				if (tokens[i].type == TOKEN_REDIR && tokens[i].redirection[0] == REDIR_PIPE)
				{
					close(pipe_fds[0]);
					close(pipe_fds[1]);
				}
				execvp(tokens[i].command[0], tokens[i].command);
				perror("execvp");
				exit(EXIT_FAILURE);
			}
			else if (pid < 0)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			int status;
			waitpid(pid, &status, 0);
			close(fd_in);
			close(fd_out);
			if (tokens[i].type == TOKEN_REDIR && tokens[i].redirection[0] == REDIR_PIPE)
				close(pipe_fds[0]);
			fd_in = STDIN_FILENO;
			fd_out = STDOUT_FILENO;
		}

		i++;
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
