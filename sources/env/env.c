/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:52:13 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/14 15:30:49 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_path(t_minishell *ms)
{
	char	*envp;

	envp = getenv("PATH");
	ms->path = envp;
}

char	*get_path(t_minishell *ms)
{
	return (ms->path);
}

int	is_builtin(char *cmd)
{
	int	l;

	l = ft_strlen(cmd);
	if (ft_strncmp(cmd, "cd", l) || ft_strncmp(cmd, "echo", l)
		|| ft_strncmp(cmd, "env", l) || ft_strncmp(cmd, "exit", l)
		|| ft_strncmp(cmd, "export", l) || ft_strncmp(cmd, "pwd", l)
		|| ft_strncmp(cmd, "unset", l)
	)
		return (1);
	return (0);
}

char	*get_path_for_cmd(char *cmd, t_minishell *ms)
{
	char	**paths;
	char	*command;
	char	*path;
	int		i;

	if (is_builtin(cmd))
		return ("builtin");
	command = ft_strjoin("/", cmd);
	paths = ft_split(get_path(ms), ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], command);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}

int	is_in_env(char *cmd, t_minishell *ms)
{
	if (get_path_for_cmd(cmd, ms) == NULL)
		return (1);
	return (0);
}
