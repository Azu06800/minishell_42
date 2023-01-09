/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:12:57 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 16:46:17 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*redir_type_to_str(t_parser_token *token)
{
	if (token->redirection[0] == REDIR_IN)
		return ("<");
	if (token->redirection[0] == REDIR_OUT)
		return (">");
	if (token->redirection[0] == REDIR_APPEND)
		return (">>");
	if (token->redirection[0] == REDIR_HEREDOC)
		return ("<<");
	if (token->redirection[0] == REDIR_PIPE)
		return ("|");
	return (NULL);
}
