/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:25:02 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/10 14:37:23 by emorvan          ###   ########.fr       */
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

int	execute_command(t_parser_token *token, int fd_in, int fd_out)
{
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
	g_minishell->cur_proc_pid = fork();
	if (g_minishell->cur_proc_pid == 0)
	{
		redir_fds(fd_in, fd_out);
		if (execve(command, args, g_minishell->envp) < 0)
		{
			ft_perror_cmd(token->command[0]);
			exit(1);
		}
	}
	else if (g_minishell->cur_proc_pid < 0)
	{
		perror("minishell: error creating child process");
		exit(1);
	}
	else
	{
		if (waitpid(g_minishell->cur_proc_pid, &status, 0) == -1)
		{
			perror("minishell: waitpid");
			return (1);
		}
	}
	free(args);
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
		perror("minishell: error allocating memory for heredoc content");
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
		tmp = ft_realloc(heredoc_content, ft_strlen(heredoc_content) + len + 2);
		if (tmp == NULL)
		{
			perror("minishell: error reallocating memory for heredoc content");
			exit(1);
		}
		heredoc_content = tmp;
		ft_strcat(heredoc_content, line);
		ft_strcat(heredoc_content, "\n");
		free(line);
	}
	return (heredoc_content);
}
