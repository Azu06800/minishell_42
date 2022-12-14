/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:59:43 by baroun            #+#    #+#             */
/*   Updated: 2022/12/14 16:35:41 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		tester_lexer(token);
		ft_parsing(token);
		ft_freeall(token, str);
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
