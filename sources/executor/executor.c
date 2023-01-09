/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:31:26 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 19:00:45 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

pid_t	g_pid;

int	handle_redirections_in(t_parser_token *tokens, int i, int *skip_next_cmd)
{
	int				fd_in;
	t_parser_token	*tmp;
	char			*heredoc_content;
	int				fd;

	fd_in = STDIN_FILENO;
	if (tokens[i + 1].type == TOKEN_REDIR)
	{
		if (tokens[i + 1].redirection[0] == REDIR_IN)
		{
			tmp = &tokens[i + 2];
			*skip_next_cmd = 1;
			fd_in = open(tmp->command[0], O_RDONLY);
		}
		else if (tokens[i + 1].redirection[0] == REDIR_HEREDOC)
		{
			heredoc_content = read_heredoc(tokens[i + 2].command[0]);
			fd = open("/tmp/heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
			write(fd, heredoc_content, ft_strlen(heredoc_content));
			*skip_next_cmd = 1;
			fd_in = open("/tmp/heredoc_tmp", O_RDONLY);
		}
	}
	return (fd_in);
}

int	handle_redirections_out(t_parser_token *tokens, int i, int *skip_next_cmd)
{
	int				fd_out;
	t_parser_token	*tmp;

	fd_out = STDOUT_FILENO;
	if (tokens[i + 1].type == TOKEN_REDIR)
	{
		if (tokens[i + 1].redirection[0] == REDIR_OUT)
		{
			tmp = &tokens[i + 2];
			*skip_next_cmd = 1;
			fd_out = open(tmp->command[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}
		else if (tokens[i + 1].redirection[0] == REDIR_APPEND)
		{
			tmp = &tokens[i + 2];
			*skip_next_cmd = 1;
			fd_out = open(tmp->command[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
	}
	return (fd_out);
}

int	ft_executor(t_parser_token *tokens, t_minishell *minishell)
{
	int	fd_in;
	int	fd_out;
	int	skip_next_cmd;
	int	i;
	int	fd[2];

	fd_in = STDIN_FILENO;
	fd_out = STDOUT_FILENO;
	skip_next_cmd = 0;
	i = 0;
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens[i].type == TOKEN_CMD)
		{
			if (skip_next_cmd)
			{
				skip_next_cmd = 0;
				i++;
				continue ;
			}
			if (tokens[i + 1].type == TOKEN_REDIR
				&& tokens[i + 1].redirection[0] == REDIR_PIPE)
			{
				if (pipe(fd) < 0)
				{
					perror("Error creating pipe");
					exit(1);
				}
				fd_out = fd[1];
			}
			fd_in = handle_redirections_in(tokens, i, &skip_next_cmd);
			fd_out = handle_redirections_out(tokens, i, &skip_next_cmd);
			if (is_builtin(minishell, tokens[i].command[0]))
				execute_builtin(&tokens[i], minishell, fd_in, fd_out);
			else
			{
				if (cmd_exists(&tokens[i], minishell))
					execute_command(&tokens[i], minishell, fd_in, fd_out);
				else
					err_not_found(tokens[i].command[0]);
			}
		}
		i++;
	}
	return (0);
}
