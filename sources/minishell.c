/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:59:43 by baroun            #+#    #+#             */
/*   Updated: 2022/11/25 16:34:38 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_minishell(t_minishell *minishell)
{
	int	nb_builtins;

	nb_builtins = 7;
	minishell->builtins = malloc(sizeof(char *) * nb_builtins);
	minishell->builtins[0] = "echo";
	minishell->builtins[1] = "cd";
	minishell->builtins[2] = "pwd";
	minishell->builtins[3] = "export";
	minishell->builtins[4] = "unset";
	minishell->builtins[5] = "env";
	minishell->builtins[6] = "exit";
}

static void	shell_loop(t_minishell *minishell)
{
	struct termios	term;
	int				ret;

	ret = tcgetattr(0, &term);
	// populate termios params with built-ins
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*minishell;

	if (ac == 1)
	{
		minishell = malloc(sizeof(t_minishell));
		if (!minishell)
			return (0);
		minishell->env = env;
		init_minishell(minishell);
	}
}
