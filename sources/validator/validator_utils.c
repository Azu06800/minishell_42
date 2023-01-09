/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:12:57 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 00:17:52 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    *redir_type_to_str(t_parser_token *token)
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