/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:25:02 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 22:03:21 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_builtin(t_parser_token *token, t_minishell *minishell)
{
	if (token->command[0] && !ft_strcmp(token->command[0], "echo"))
		exit(ft_echo(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "cd"))
		exit(ft_cd(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "pwd"))
		exit(ft_pwd(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "export"))
		exit(ft_export(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "unset"))
		exit(ft_unset(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "env"))
		exit(ft_env(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "exit"))
		exit(ft_exit(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "clear"))
		exit(ft_clear(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "history"))
		exit(ft_history(token, minishell));
	return (0);
}

int	is_builtin(t_minishell *minishell, char *str)
{
	int	i;

	i = 0;
	while (minishell->builtins[i])
	{
		if (!ft_strcmp(str, minishell->builtins[i]))
			return (1);
		i++;
	}
	return (0);
}

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

int	execute_command(t_parser_token *token, t_minishell *minishell, int fd_in,
	int fd_out)
{
	int		pid;
	int		status;
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
	pid = fork();
	if (pid == 0)
	{
		redir_fds(fd_in, fd_out);
		if (execve(command, args, minishell->envp) < 0)
		{
			perror("Error executing command");
			exit(1);
		}
	}
	else if (pid < 0)
	{
		perror("Error creating child process");
		exit(1);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (1);
		}
	}
	free(args);
	return (0);
}

int	execute_builtin(t_parser_token *token, t_minishell *minishell, int fd_in,
	int fd_out)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		redir_fds(fd_in, fd_out);
		if (exec_builtin(token, minishell) < 0)
		{
			perror("Error executing command");
			exit(1);
		}
	}
	else if (pid < 0)
	{
		perror("Error creating child process");
		exit(1);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (1);
		}
		ft_modenv(minishell, "$?", ft_itoa(status));
	}
	return (0);
}

char	*read_heredoc(char *delimiter)
{
	char	*line;
	int		len;
	int		delimiter_len;
	char	*heredoc_content;
	char	*tmp;

	line = NULL;
	len = 0;
	delimiter_len = ft_strlen(delimiter);
	heredoc_content = malloc(1);
	if (heredoc_content == NULL)
	{
		perror("Error allocating memory for heredoc content");
		exit(1);
	}
	heredoc_content[0] = '\0';
	while (1)
	{
		line = readline("heredoc> ");
		if (line == NULL)
			break ;
		len = ft_strlen(line);
		if (len == delimiter_len && ft_strncmp(line, delimiter, delimiter_len)
			== 0)
		{
			free(line);
			break ;
		}
		tmp = realloc(heredoc_content, ft_strlen(heredoc_content) + len + 2);
		if (tmp == NULL)
		{
			perror("Error reallocating memory for heredoc content");
			exit(1);
		}
		heredoc_content = tmp;
		ft_strcat(heredoc_content, line);
		ft_strcat(heredoc_content, "\n");
		free(line);
	}
	return (heredoc_content);
}