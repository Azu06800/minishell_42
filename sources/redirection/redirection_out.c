/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:45:29 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 19:46:54 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
			fd_out = open(tmp->command[0], O_WRONLY | O_CREAT | O_TRUNC,
					0644);
		}
		else if (tokens[i + 1].redirection[0] == REDIR_APPEND)
		{
			tmp = &tokens[i + 2];
			*skip_next_cmd = 1;
			fd_out = open(tmp->command[0], O_WRONLY | O_CREAT | O_APPEND,
					0644);
		}
	}
	return (fd_out);
}
