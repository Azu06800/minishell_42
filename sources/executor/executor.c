/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:31:26 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/27 19:31:25 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_bin(t_parser_token *token)
{
	// currently unstable
	(void) token;
}

void	ft_executor(t_parser_token *tokens, t_minishell *minishell)
{
	size_t	i;

	i = 0;
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens->type == TOKEN_CMD)
		{
			if (tokens->command[0] && !ft_strcmp(tokens->command[0], "echo"))
				ft_echo(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "cd"))
				ft_cd(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "pwd"))
				ft_pwd(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "export"))
				ft_export(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "unset"))
				ft_unset(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "env"))
				ft_env(tokens, minishell);
			else if (tokens->command[0] && !ft_strcmp(tokens->command[0], "exit"))
				ft_exit(tokens, minishell);
			else
				exec_bin(tokens);
		}
		i++;
	}
}
