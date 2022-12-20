/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:26:52 by baroun            #+#    #+#             */
/*   Updated: 2022/12/20 14:58:30 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cmp_str(char *str, char *cmp)
{
	int	i;

	i = -1;
	while (cmp[++i])
	{
		if (str[i] != cmp[i])
			return (0);
	}
	return (1);
}

void	ft_parsing(char **token, t_minishell *minishell)
{
	if (cmp_str(token[0], "echo"))
		ft_echo(token, minishell);
	else if (cmp_str(token[0], "cd"))
		ft_cd(token, minishell);
	else if (cmp_str(token[0], "pwd"))
		ft_pwd(token, minishell);
	else if (cmp_str(token[0], "export"))
		ft_export(token, minishell);
	else if (cmp_str(token[0], "unset"))
		ft_unset(token, minishell);
	else if (cmp_str(token[0], "env"))
		ft_env(token, minishell);
	else if (cmp_str(token[0], "exit"))
		ft_exit(token, minishell);
}
