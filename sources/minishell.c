/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:59:43 by baroun            #+#    #+#             */
/*   Updated: 2023/01/01 23:17:04 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_minishell(t_minishell *minishell)
{
	minishell->builtins = malloc(sizeof(char *) * 7);
	minishell->builtins[0] = "echo";
	minishell->builtins[1] = "cd";
	minishell->builtins[2] = "pwd";
	minishell->builtins[3] = "export";
	minishell->builtins[4] = "unset";
	minishell->builtins[5] = "env";
	minishell->builtins[6] = "exit";
}

void	ft_freeall(char **token, char *str)
{
	int	i;

	i = -1;
	while (token[++i])
		free(token[i]);
	free(token[i]);
	free(str);
	free(token);
}

void	boucle(t_minishell *minishell)
{
	char			*str;
	char			**token;
	t_parser_token	*parser_token;

	init_signal();
	while (1)
	{
		str = readline("minishell$ ");
		if (str == NULL)
			continue ;
		if (*str == '\0')
			continue ;
		add_history(str);
		if (err_unclosed_quote(str))
			continue ;
		token = ft_lexer(str);
		parser_token = ft_parse_tokens(token, minishell);
		ft_expander(parser_token, minishell);
		print_token(parser_token);
		ft_executor(parser_token, minishell);
	}
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*minishell;

	(void) av;
	if (ac == 1)
	{
		minishell = malloc(sizeof(t_minishell));
		if (!minishell)
			return (0);
		ft_initenv(minishell, env);
		init_minishell(minishell);
		boucle(minishell);
	}
	return (1);
}
