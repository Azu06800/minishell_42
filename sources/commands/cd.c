/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:50:36 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/27 19:24:30 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cd(t_parser_token *token, t_minishell *minishell)
{
	char	*home;

	(void) minishell;
	if (token->command[1] == NULL)
	{
		home = getenv("HOME");
		if (home == NULL)
			return (0);
		if (chdir(home) != 0)
		{
			perror("cd");
			return (1);
		}
	}
	else
	{
		if (chdir(token->command[1]) != 0)
		{
			write(1, "minishell: cd: ", 15);
			write(1, token->command[1], strlen(token->command[1]));
			write(1, ": No such file or directory\n", 28);
			return (1);
		}
	}
	return (0);
}
