/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:12:46 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/10 18:53:33 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	echo_quote(char *str)
{
	int	i;

	i = -1;
	if (ft_isquote(str[0]))
		i++;
	while (str[++i])
		write(1, &str[i], 1);
}

void	ft_printwithoutquote(char *str)
{
	int	i;

	i = 0;
	while (str[++i] != str[0])
		write(1, str + i, 1);
}

void	ft_echoboucle(t_parser_token *token, int i)
{
	while (token->command[i])
	{
		if (ft_isquote(token->command[i][0]))
			ft_printwithoutquote(token->command[i]);
		else
			printf("%s", token->command[i]);
		if (token->command[i + 1] && token->tokens[i + 1].spcecho)
			write(1, " ", 1);
		i++;
	}
}

int	ft_echo(t_parser_token *token)
{
	int	i;
	int	nflag;

	i = 1;
	nflag = 0;
	token++;
	if (token->type == TOKEN_REDIR
		&& token->redirection[0] == REDIR_HEREDOC)
	{
		printf("\n");
		token--;
		return (0);
	}
	token--;
	if (token->command[1] && ft_strcmp(token->command[1], "-n") == 0)
	{
		nflag = 1;
		i++;
	}
	ft_echoboucle(token, i);
	if (!nflag)
		printf("\n");
	return (0);
}
