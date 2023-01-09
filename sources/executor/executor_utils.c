/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:25:14 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 15:25:52 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	cmd_exists(t_parser_token *token, t_minishell *minishell)
{
	char	**path;

	path = ft_split(ft_getenv(minishell, "PATH"), ':');
	while (path && *path)
	{
		char *cmd = ft_strcat(*path, "/");
		cmd = ft_strcat(cmd, token->command[0]);
		if (access(cmd, F_OK) == 0)
		{
			token->command[0] = ft_strdup(cmd);
			free(cmd);
			return (1);
		}
		free(cmd);
		path++;
	}
	return (0);
}
