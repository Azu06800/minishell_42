/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:50:36 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/01 22:56:33 by emorvan          ###   ########.fr       */
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

int	ft_cd_no_arg(t_minishell *minishell, t_parser_token *token)
{
	char	*home;

	if (token->command[1] == NULL)
	{
		home = ft_getenv(minishell, "HOME");
		if (home == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (2);
		}
		if (chdir(home) != 0)
		{
			ft_cd_error("cd", home);
			return (2);
		}
		return (1);
	}
	return (0);
}

int	ft_cd_one_arg(t_parser_token *token)
{
	if (token->command[2] == NULL)
	{
		if (chdir(token->command[1]) != 0)
		{
			ft_cd_error("minishell: cd", token->command[1]);
			return (2);
		}
		return (1);
	}
	return (0);
}

int	ft_cd(t_parser_token *token, t_minishell *minishell)
{
	char	*cur_dir;
	char	*oldpwd;

	if (ft_cd_no_arg(minishell, token) == 2)
		return (0);
	if (ft_cd_no_arg(minishell, token) == 1)
	{
		printf("a");
		cur_dir = getcwd(NULL, 0);
		ft_modenv(minishell, "PWD", cur_dir);
		free(cur_dir);
		oldpwd = ft_getenv(minishell, "OLDPWD");
		ft_modenv(minishell, "OLDPWD", oldpwd);
		return (1);
	}
	if (ft_cd_one_arg(token) == 2)
		return (0);
	if (ft_cd_one_arg(token) == 1)
	{
		printf("b");
		cur_dir = getcwd(NULL, 0);
		ft_modenv(minishell, "PWD", cur_dir);
		free(cur_dir);
		oldpwd = ft_getenv(minishell, "OLDPWD");
		ft_modenv(minishell, "OLDPWD", oldpwd);
		return (1);
	}
	ft_putstr_fd("minishell: cd: too many arguments\n", 2);
	return (0);
}
