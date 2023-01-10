/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:34:24 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 19:46:53 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_norme(int i, int *skip_next_cmd, t_parser_token *tokens)
{
	int				fd;
	int				fd_in;
	char			*heredoc_content;

	fd_in = STDIN_FILENO;
	heredoc_content = read_heredoc(tokens[i + 2].command[0]);
	fd = open("/tmp/heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, heredoc_content, ft_strlen(heredoc_content));
	*skip_next_cmd = 1;
	if (tokens[i].command[0]
		&& ft_strcmp(tokens[i].command[0], "echo"))
		fd_in = open("/tmp/heredoc_tmp", O_RDONLY);
	return (fd_in);
}

int	handle_redirections_in(t_parser_token *tokens, int i, int *skip_next_cmd)
{
	int				fd_in;
	t_parser_token	*tmp;

	fd_in = STDIN_FILENO;
	if (tokens[i + 1].type == TOKEN_REDIR)
	{
		if (tokens[i + 1].redirection[0] == REDIR_IN)
		{
			tmp = &tokens[i + 2];
			*skip_next_cmd = 1;
			if (!access(tmp->command[0], F_OK | R_OK))
				fd_in = open(tmp->command[0], O_RDONLY);
			else
				return (-1337);
		}
		else if (tokens[i + 1].redirection[0] == REDIR_HEREDOC)
			fd_in = handle_norme(i, skip_next_cmd, tokens);
	}
	return (fd_in);
}
