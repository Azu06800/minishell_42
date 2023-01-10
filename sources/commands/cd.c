/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:50:36 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/10 11:46:14 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cd_error(char *s1, char *s2)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

int	ft_cd_no_arg(char *oldpwd)
{
	char	*home;

	home = ft_getenv("HOME");
	if (home == NULL)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(home) != 0)
	{
		ft_cd_error("cd", home);
		return (1);
	}
	ft_modenv("PWD", home);
	ft_modenv("OLDPWD", oldpwd);
	return (0);
}

int	ft_cd_one_arg(t_parser_token *token, char *oldpwd)
{
	char	*newpwd;

	if (chdir(token->command[1]) != 0)
	{
		ft_cd_error("minishell: cd", token->command[1]);
		return (1);
	}
	newpwd = getcwd(NULL, 0);
	ft_modenv("PWD", newpwd);
	ft_modenv("OLDPWD", oldpwd);
	return (0);
}

int	ft_cd(t_parser_token *token)
{
	char	*oldpwd;

	oldpwd = getcwd(NULL, 0);
	if (token->command[1] == NULL)
	{
		if (ft_cd_no_arg(oldpwd) == 1)
			return (1);
		return (0);
	}
	if (token->command[2] == NULL)
	{
		if (ft_cd_one_arg(token, oldpwd) == 1)
			return (1);
		return (0);
	}
	if (token->command[2] != NULL)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	return (0);
}
