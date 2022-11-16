/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:52:13 by emorvan           #+#    #+#             */
/*   Updated: 2022/11/16 17:59:05 by emorvan          ###   ########.fr       */
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
	if (cmd == "cd" || cmd == "echo" || cmd == "env" || cmd == "exit"
		|| cmd == "export" || cmd == "pwd" || cmd == "unset")
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
