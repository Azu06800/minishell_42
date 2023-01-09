/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:09:24 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 17:11:35 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_redirect(char *token)
{
	return (ft_strcmp(token, "<") == 0 || ft_strcmp(token, ">") == 0
		|| ft_strcmp(token, ">>") == 0 || ft_strcmp(token, "<<") == 0
		|| ft_strcmp(token, "|") == 0);
}

t_redir_type	get_redir_type(char *token)
{
	if (ft_strcmp(token, ">>") == 0)
		return (REDIR_APPEND);
	else if (ft_strcmp(token, "<<") == 0)
		return (REDIR_HEREDOC);
	else if (ft_strcmp(token, "<") == 0)
		return (REDIR_IN);
	else if (ft_strcmp(token, ">") == 0)
		return (REDIR_OUT);
	else if (ft_strcmp(token, "|") == 0)
		return (REDIR_PIPE);
	return (REDIR_ERROR);
}

size_t	count_tokens(char **tokens)
{
	size_t	num_tokens;

	num_tokens = 0;
	while (tokens[num_tokens] != NULL)
		num_tokens++;
	return (num_tokens);
}

void	parse_tokens(char **tokens, t_parser_token *parsed_tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (is_redirect(tokens[i]))
		{
			parse_redirect_token(tokens[i], &parsed_tokens[i]);
		}
		else if (ft_strcmp(tokens[i], ";") == 0)
		{
			parse_separator_token(tokens[i], &parsed_tokens[i]);
		}
		else
		{
			parse_command_token(tokens, i, &parsed_tokens[i]);
			i += parsed_tokens[i].command_size - 1;
		}
		i++;
	}
}

t_parser_token	*ft_parse_tokens(char **tks, t_minishell *mshell, t_tokens *tk)
{
	size_t			num_tokens;
	t_parser_token	*parsed_tokens;

	(void) mshell;
	num_tokens = count_tokens(tks);
	parsed_tokens = malloc((num_tokens + 1) * sizeof(t_parser_token));
	parsed_tokens->tokens = tk;
	if (parsed_tokens == NULL)
		return (NULL);
	parse_tokens(tks, parsed_tokens);
	parsed_tokens[num_tokens].type = TOKEN_END;
	remove_empty_cmd(parsed_tokens);
	return (parsed_tokens);
}
