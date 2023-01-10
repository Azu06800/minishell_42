/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:14:32 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 20:19:58 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redir_fds(int fd_in, int fd_out)
{
	if (fd_in != STDIN_FILENO)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (fd_out != STDOUT_FILENO)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
}

void	exlael(int fd_out, int fd_in, int fd[2])
{
	if (fd_out != STDOUT_FILENO && fd_out == fd[1])
		close(fd_out);
	if (fd_in != STDIN_FILENO && fd_in == fd[0])
	{
		close(fd_in);
	}
}

void	exeli(int fd_in, int fd_out, char *command, char **args)
{
	redir_fds(fd_in, fd_out);
	if (execve(command, args, g_minishell->envp) < 0)
	{
		ft_perror_cmd(command);
		close(fd_in);
		close(fd_out);
		exit(1);
	}
}

int	execute_command(t_parser_token *token, int fd_in, int fd_out, int fd[2])
{
	char	*command;
	char	**args;
	size_t	i;

	command = token->command[0];
	args = malloc((token->command_size + 1) * sizeof(char *));
	i = 0;
	while (i < token->command_size)
	{
		args[i] = token->command[i];
		i++;
	}
	args[token->command_size] = NULL;
	g_minishell->cur_proc_pid = fork();
	if (g_minishell->cur_proc_pid == 0)
		exeli(fd_in, fd_out, command, args);
	else if (g_minishell->cur_proc_pid < 0)
	{
		perror("minishell: error creating child process");
		exit(1);
	}
	else
		exlael(fd_out, fd_in, fd);
	free(args);
	return (0);
}
