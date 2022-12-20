/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:33:36 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/21 00:37:44 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parse_redirect_token(char *token, t_parser_token *parsed_token)
{
	parsed_token->type = TOKEN_REDIR;
	parsed_token->redirection[0] = get_redir_type(token);
}

void	parse_separator_token(char *token, t_parser_token *parsed_tok)
{
	(void) token;
	parsed_tok->type = TOKEN_SEP;
}

void	parse_command_token(char **tk, size_t i, t_parser_token *p_tk)
{
	size_t	j;

	p_tk->type = TOKEN_CMD;
	j = 0;
	while (tk[i + j] != NULL && !is_redirect(tk[i + j])
		&& ft_strcmp(tk[i + j], ";") != 0)
		j++;
	p_tk->command_size = j;
	p_tk->command = tk + i;
}
