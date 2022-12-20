/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:50:36 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/17 15:01:32 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cd(char **token, t_minishell *minishell)
{
	char	*home;

	(void) minishell;
	if (token[1] == NULL)
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
		if (chdir(token[1]) != 0)
		{
			write(1, "minishell: cd: ", 15);
			write(1, token[1], strlen(token[1]));
			write(1, ": No such file or directory\n", 28);
			return (1);
		}
	}
	return (0);
}
