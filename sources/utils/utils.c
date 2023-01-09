/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:54:32 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 00:25:15 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ftl_cinstr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_onlyspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_freeall(char **token, char *str)
{
	int	i;

	i = -1;
	while (token[++i])
		free(token[i]);
	free(token[i]);
	free(str);
	free(token);
}

void	ft_perror_cmd(char *cmd)
{
	char	*message;

	message = ft_strjoin("minishell: ", cmd);
	perror(message);
	free(message);
}
