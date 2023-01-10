/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:31:26 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/10 20:52:23 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute(t_parser_token *token, int *fd_in, int *fd_out, int fd[2])
{
	if (is_builtin(token->command[0]))
		execute_builtin(token, *fd_in, *fd_out);
	else
	{
		if (cmd_exists(token))
			execute_command(token, *fd_in, *fd_out, fd);
		else
			err_not_found(token->command[0]);
	}
	if (*fd_out != STDOUT_FILENO && *fd_out == fd[1])
	{
		close(*fd_out);
		*fd_in = fd[0];
	}
}

void	ft_excnorme(int *fd_in, int *fd_out, t_parser_token *tokens, int *i)
{
	int	skip_next_cmd;
	int	fd[2];

	skip_next_cmd = 0;
	if (skip_next_cmd)
	{
		skip_next_cmd = 0;
		(*i)++;
		return ;
	}
	if (tokens[(*i) + 1].type == TOKEN_REDIR
		&& tokens[(*i) + 1].redirection[0] == REDIR_PIPE)
	{
		pipe(fd);
		*fd_out = fd[1];
	}
	else
	{
		if (tokens[(*i) - 1].type != TOKEN_REDIR
			&& tokens[(*i) - 1].redirection[0] != REDIR_PIPE)
			*fd_in = handle_redirections_in(tokens, (*i), &skip_next_cmd);
		*fd_out = handle_redirections_out(tokens, (*i), &skip_next_cmd);
	}
	execute(&tokens[(*i)], fd_in, fd_out, fd);
}

int	ft_executor(t_parser_token *tokens)
{
	int	fd_in;
	int	fd_out;
	int	i;
	int	j;

	fd_in = STDIN_FILENO;
	fd_out = STDOUT_FILENO;
	i = 0;
	while (tokens[i].type != TOKEN_END)
	{
		ft_excnorme(&fd_in, &fd_out, tokens, &i);
		i++;
	}
	j = 3;
	while (j != 0)
	{
		wait(NULL);
		j--;
	}
	return (0);
}
