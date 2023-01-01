/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:33:36 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/01 23:06:21 by emorvan          ###   ########.fr       */
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

void	remove_empty_cmd(t_parser_token *parsed_tokens)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (parsed_tokens[i].type != TOKEN_END)
	{
		if (parsed_tokens[i].type == TOKEN_CMD)
		{
			if (parsed_tokens[i].command_size == 0)
			{
				j = i;
				while (parsed_tokens[j].type != TOKEN_END)
				{
					parsed_tokens[j] = parsed_tokens[j + 1];
					j++;
				}
				i--;
			}
		}
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return (
				(char*)s
			);
		s++;
	}
	if (c == (char) '\0')
		return (
			(char*)s
		);
	return (NULL);
}
