/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:59:43 by baroun            #+#    #+#             */
/*   Updated: 2022/12/14 15:29:01 by emorvan          ###   ########.fr       */
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

void	boucle(void)
{
	char	*str;
	char	**token;

	signal(SIGINT, ctrl_c);
	while (1)
	{
		str = readline(PROMPT);
		if (*str == '\0')
			continue ;
		add_history(str);
		if (err_unclosed_quote(str))
			continue ;
		token = ft_lexer(str);
		free(str);
		tester_lexer(token);
		ft_parsing(token);
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
		minishell->env = env;
		init_minishell(minishell);
		boucle();
	}
	return (1);
}
