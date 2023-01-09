/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:01:11 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 16:40:30 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_token_type(t_parser_token *token)
{
	printf("Type: ");
	if (token->type == TOKEN_CMD)
		printf("TOKEN_CMD\n");
	else if (token->type == TOKEN_REDIR)
		printf("TOKEN_REDIR\n");
	else if (token->type == TOKEN_SEP)
		printf("TOKEN_SEP\n");
	else if (token->type == TOKEN_END)
		printf("TOKEN_END\n");
}

void	print_token_redir(t_parser_token *token)
{
	printf("Redirection: ");
	if (token->redirection[0] == REDIR_IN)
		printf("REDIR_IN\n");
	else if (token->redirection[0] == REDIR_OUT)
		printf("REDIR_OUT\n");
	else if (token->redirection[0] == REDIR_APPEND)
		printf("REDIR_APPEND\n");
	else if (token->redirection[0] == REDIR_HEREDOC)
		printf("REDIR_HEREDOC\n");
	else if (token->redirection[0] == REDIR_PIPE)
		printf("REDIR_PIPE\n");
	else if (token->redirection[0] == REDIR_ERROR)
		printf("REDIR_ERROR\n");
}

void	print_token_command(t_parser_token *token)
{
	size_t	i;

	i = 0;
	printf("Command: ");
	while (i < token->command_size)
	{
		printf("%s ", token->command[i]);
		i++;
	}
	printf("\nCommand size: %zu\n", token->command_size);
}

void	print_token(t_parser_token *token)
{
	size_t	i;

	i = 0;
	while (token[i].type != TOKEN_END)
	{
		printf("===============\n");
		print_token_type(&token[i]);
		if (token[i].type == TOKEN_REDIR)
			print_token_redir(&token[i]);
		if (token[i].type == TOKEN_CMD)
			print_token_command(&token[i]);
		printf("===============\n");
		i++;
	}
}
